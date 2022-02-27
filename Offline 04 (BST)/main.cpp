#include <iostream>
#include <fstream>
#include "BST.cpp"

using namespace std;

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
    BST<int, int> ob;
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
            in_file >> val;
            if (c == 'I') {
                // insert
                ob.insert(val, val);
                ob.print_tree();
            }
            else if (c == 'D') {
                // remove
                if (ob.remove(val)) ob.print_tree();
                else cout << "Invalid Operation\n";
            }
            else {
                // find
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
