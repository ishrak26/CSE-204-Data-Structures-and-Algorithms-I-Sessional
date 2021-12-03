#include <iostream>
#include <assert.h>
#include "Stack.h"
#include "Arr.cpp"
#include "LL.cpp"

using namespace std;

class dw {
    char implementation;
    int n; // no. of friends
    int x; // no. of courses
    int *courses;
    Stack<int> *dirty; // keeps track of dirty dishes
    Stack<int> *clean; // keeps track of clean dishes
    int *meal_count; // keeps track of which friend completed how many meals
    Stack<int> *full_meals; // keeps track of which friend completed full meal

    int curr_wash_end_time;

    void alloc_mem() {
        courses = new int[x];
        meal_count = new int[n];
        for (int i = 0; i < n; i++) {
            meal_count[i] = 0;
        }

        if (implementation == 'A') {
            dirty = new Arr<int>;
            clean = new Arr<int>;
            full_meals = new Arr<int>;
        }
        else if (implementation == 'L') {
            dirty = new LL<int>;
            clean = new LL<int>;
            full_meals = new LL<int>;
        }
        else {
            // One Array Two Stack
            int *arr = new int[n*x]; // no further resizing needed
            dirty = new Arr<int>(arr, 1);
            clean = new Arr<int>(arr, -1);
            full_meals = new Arr<int>;
        }
    }

    void clear_dirty_stack() {
        while (dirty->length()) {
            curr_wash_end_time += dirty->pop();
            clean->push(curr_wash_end_time);
        }
    }

    void print_stack(Stack<int> *s) {
        Arr<int> tmp;
        while (s->length()) {
            tmp.push(s->pop());
        }
        bool flag = false;
        while (tmp.length()) {
            if (flag) cout << ',';
            cout << tmp.topValue();
            if (!flag) {
                flag = true;
            }
            s->push(tmp.pop());
        }
        cout << "\n";
    }

public:
    dw(int n, int x, char implementation = 'A') {
        curr_wash_end_time = -1;

        assert(n > 0);
        this->n = n;

        assert(x > 0);
        this->x = x;

        assert(implementation == 'A' || implementation == 'L' || implementation == 'T');
        this->implementation = implementation;

        alloc_mem();
    }

    ~dw() {
        delete[] courses;
        delete[] meal_count;

        if (implementation == 'A') {
            delete (Arr<int>*) dirty;
            delete (Arr<int>*) clean;
            delete (Arr<int>*) full_meals;
        }

        else if (implementation == 'L') {
            delete (LL<int>*) dirty;
            delete (LL<int>*) clean;
            delete (LL<int>*) full_meals;
        }
        else {
            // One Array Two Stack
            delete (Arr<int>*) dirty;// clearing any of clean or dirty would do
            delete (Arr<int>*) clean;
            delete (Arr<int>*) full_meals;
        }
    }

    void set_course(int course_no, int time) {
        courses[course_no] = time;
    }

    void add_dirty_dish(int friend_no, int time, int course_no) {
        if (friend_no == 0) {
            clear_dirty_stack();
            return;
        }

        --friend_no;
        --course_no;

        if (time <= curr_wash_end_time) {
            dirty->push(courses[course_no]);
        }
        else {
            clear_dirty_stack();

            // curr_wash_end_time = max(curr_wash_end_time, time) + courses[course_no] - 1;
            curr_wash_end_time = curr_wash_end_time > time ? curr_wash_end_time : time;
            curr_wash_end_time += courses[course_no] - 1;

            clean->push(curr_wash_end_time);
        }

        ++meal_count[friend_no];
        if (meal_count[friend_no] == x) {
            full_meals->push(friend_no + 1);
        }
    }

    int print_end_time() {
        assert(clean->length());
        return clean->topValue();
    }

    void print_clean_stack() {
        print_stack(clean);
    }

    bool check_all_full_meal() {
        for (int i = 0; i < n; i++) {
            if (meal_count[i] != x) return false;
        }
        return true;
    }

    void print_full_meals() {
        Arr<int> tmp;
        bool flag = false;
        while (full_meals->length()) {
            if (flag) cout << ',';
            cout << full_meals->topValue();
            if (!flag) flag = true;
            tmp.push(full_meals->pop());
        }
        while (tmp.length()) {
            full_meals->push(tmp.pop());
        }
        cout << "\n";
    }
};

int main() {
    int n, x;
    cin >> n >> x;
    dw ob(n, x, 'L');
    for (int i = 0; i < x; i++) {
        int time;
        cin >> time;
        ob.set_course(i, time);
    }
    int k, t, s;
    while (true) {
        cin >> k >> t >> s;
        ob.add_dirty_dish(k, t, s);
        if (k == 0) break;
    }
    cout << ob.print_end_time() << "\n";
    ob.print_clean_stack();
    if (ob.check_all_full_meal()) {
        cout << 'Y';
    }
    else {
        cout << 'N';
    }
    cout << "\n";
    ob.print_full_meals();
    return 0;
}
