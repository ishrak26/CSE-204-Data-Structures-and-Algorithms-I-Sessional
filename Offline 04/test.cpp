#include <iostream>
#include <fstream>
#include "BST.cpp"

using namespace std;

class test {
    int x, y;
public:
    test() {
        x = y = -1;
    }
    void setx(int x) {this->x = x;}
    void sety(int y) {this->y = y;}
    int getx() {return x;}
    int gety() {return y;}
    friend istream &operator>>(istream &stream, test &ob) {
        stream >> ob.x >> ob.y;
        return stream;
    }
    friend ostream &operator<<(ostream &stream, test ob) {
        stream << '(' << ob.x << ", " << ob.y << ')';
        return stream;
    }
};

int main(int argc, char **argv) {
    if (argc != 2) {
        cerr << "Usage: filename" << "\n";
        return 1;
    }
    ifstream in_file(argv[1]);
    if (!in_file) {
        cerr << "Unable to open file\n";
        return 2;
    }
    char c, str[5];
    int val;
    test obj;
    BST<int, test> ob;
    while (in_file >> c) {
        if (c == 'T') {
            // traversal
            in_file >> str;
            if (str[0] == 'I') {
                // in-order traversal
                ob.print_in_order();
            }
            else if (str[1] == 'r') {
                // pre-order traversal
                ob.print_pre_order();
            }
            else {
                // post-order traversal
                ob.print_post_order();
            }
        }
        else {
            if (c == 'I') {
                // insert
                in_file >> obj;
                ob.insert(obj.getx(), obj);
                ob.print_tree();
            }
            else if (c == 'D') {
                // remove
                in_file >> val;
                if (ob.remove(val)) ob.print_tree();
                else cout << "Invalid Operation\n";
            }
            else {
                // find
                in_file >> val;
                if (ob.find(val)) {
                    cout << "True\n";
                }
                else {
                    cout << "False\n";
                }
            }
        }
    }
    in_file.close();
    return 0;
}

