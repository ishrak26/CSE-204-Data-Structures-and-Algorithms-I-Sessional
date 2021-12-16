#include <iostream>
#include <cassert>

using namespace std;

template <typename Key, typename E>
class BST {
    class Node {
    public:
        Key key;
        E val;
        Node *left;
        Node *right;

        Node(const Key key, const E val, Node *left = NULL, Node *right = NULL) {
            this->key = key;
            this->val = val;
            this->left = left;
            this->right = right;
        }

    };

    Node *root;

    inline bool isLeaf(Node *node) {
        assert(node != NULL);
        return node->left == NULL && node->right == NULL;
    }

    void inserthelp(const Key key, const E val, Node *curr) {
        assert(curr != NULL);
        if (key < curr->key) {
            if (curr->left == NULL) curr->left = new Node(key, val);
            else inserthelp(key, val, curr->left);
        }
        else {
            if (curr->right == NULL) curr->right = new Node(key, val);
            else inserthelp(key, val, curr->right);
        }
    }

    bool findhelp(const Key key, Node *curr) {
        if (curr == NULL) {
            return false;
        }
        if (key == curr->key) return true;
        if (key < curr->key) {
            return findhelp(key, curr->left);
        }
        return findhelp(key, curr->right);
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
        cout << root->val << " ";
    }

    void print_treehelp(Node *root) {
        if (root == NULL) return;
        cout << root->val;
        if (isLeaf(root)) return;
        cout << '(';
        print_treehelp(root->left);
        cout << ")(";
        print_treehelp(root->right);
        cout << ')';
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {

    }

    void insert(const Key key, const E val) {
        if (root == NULL) root = new Node(key, val);
        else inserthelp(key, val, root);
    }

    void remove(const Key key) {

    }

    bool find(const Key key) {
        return findhelp(key, root);
    }

    void print_in_order() {
        in_orderhelp(root);
        cout << "\n";
    }

    void print_pre_order() {
        pre_orderhelp(root);
        cout << "\n";
    }

    void print_post_order() {
        post_orderhelp(root);
        cout << "\n";
    }

    void print_tree() {
        print_treehelp(root);
        cout << "\n";
    }
};
