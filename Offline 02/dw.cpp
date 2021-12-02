#include <iostream>
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
    }

    void print_stack(Stack<int> *s) {
        Arr<int> tmp;
        while (s->length()) {
            tmp.push(s->pop());
        }
        while (tmp.length()) {
            cout << tmp.top() << " ";
            s->push(tmp.pop());
        }
        cout << "\n";
    }

public:
    dw(int n, int x, char implementation = 'A') {
        assert(n > 0);
        this->n = n;

        assert(x > 0);
        this->x = x;

        assert(implementation == 'A' || implementation == 'L');
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
    }

    void set_course(int course_no, int time) {
        courses[course_no] = time;
    }

    void add_dirty_dish(int friend_no, int time, int course_no) {
        --friend_no;
        --course_no;

        ++meal_count[friend_no];
        if (meal_count[friend_no] == x) {
            full_meals->push(friend_no + 1);
        }
    }

    bool check_all_full_meal() {
        for (int i = 0; i < n; i++) {
            if (meal_count[i] != x) return false;
        }
        return true;
    }

    void print_full_meals() {
        Arr<int> tmp;
        while (full_meals->length()) {
            cout << full_meals->topValue() << " ";
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
    dw ob(n, x);
    for (int i = 0; i < x; i++) {
        int time;
        cin >> time;
        ob.set_course(i, time);
    }
    int k, t, s;
    while (true) {
        cin >> k >> t >> s;
        if (k == 0) break;
        ob.add_dirty_dish(k, t, s);
    }
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
