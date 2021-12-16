#include <iostream>
#include <cassert>

using namespace std;

template <typename E>
class BST {
    class Node {
    public:
        E val;
        Node *left;
        Node *right;

        Node(const E val, Node *left = NULL, Node *right = NULL) {
            this->val = val;
            this->left = left;
            this->right = right;
        }

    };

    Node *root;

    void inserthelp(const E val, Node *curr) {
        assert(curr != NULL);
        if (val < curr->val) {
            if (curr->left == NULL) curr->left = new Node(val);
            else inserthelp(val, curr->left);
        }
        else {
            if (curr->right == NULL) curr->right = new Node(val);
            else inserthelp(val, curr->right);
        }
    }

    bool findhelp(const E val, Node *curr) {
        if (curr == NULL) {
            return false;
        }
        if (val == curr->val) return true;
        if (val < curr->val) {
            return findhelp(val, curr->left);
        }
        return findhelp(val, curr->right);
    }

    void in_orderhelp(Node *root) {
        if (root == NULL) return;
        in_orderhelp(root->left);
        cout << root->val << " ";
        in_orderhelp(root->right);
    }

    void pre_orderhelp(Node *root) {
        if (root == NULL) return;
        cout << root->val << " ";
        pre_orderhelp(root->left);
        pre_orderhelp(root->right);
    }

    void post_orderhelp(Node *root) {
        if (root == NULL) return;
        post_orderhelp(root->left);
        post_orderhelp(root->right);
        cout << root->val << "\n";
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {

    }

    void insert(const E val) {
        if (root == NULL) root = new Node(val);
        else inserthelp(val, root);
    }

    void remove(const E val) {

    }

    bool find(const E val) {
        return findhelp(val, root);
    }

    void print_in_order() {
        in_orderhelp(root);
    }

    void print_pre_order() {
        pre_orderhelp(root);
    }

    void print_post_order() {
        post_orderhelp(root);
    }
};
