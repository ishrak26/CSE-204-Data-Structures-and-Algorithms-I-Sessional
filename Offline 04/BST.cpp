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

    Node *findhelp(const Key key, Node *curr) {
        if (curr == NULL) return NULL;
        if (key == curr->key) return curr;
        if (key < curr->key) return findhelp(key, curr->left);
        return findhelp(key, curr->right);
    }

    Node *find_parenthelp(Node *curr, Node *child) {
        assert(curr != NULL);
        if (child->key == curr->left->key || child->key == curr->right->key) return curr;
        if (child->key < curr->key) return find_parenthelp(curr->left, child);
        return find_parenthelp(curr->right, child);
    }

    Node *find_min(Node *curr) {
        assert(curr != NULL);
        if (curr->left == NULL) return curr;
        return find_min(curr->left);
    }

    void removehelp(const Key key) {
        // find the node
        Node *node = findhelp(key, root);
        assert(node != NULL); // node exists
        if (node->left == NULL || node->right == NULL) {
            // node is not full
            // find parent
            if (root->key == node->key) {
                // no parent for root node
                if (isLeaf(root)) {
                    delete root;
                    root = NULL;
                }
                else {
                    // root has one empty node
                    Node *tmp = root;
                    root = root->left == NULL ? root->right : root->left;
                    delete tmp;
                }
            }
            else {
                Node *parent = find_parenthelp(root, node);
                assert(parent != NULL);
                if (isLeaf(node)) {
                    if (parent->left == node) parent->left = NULL;
                    else parent->right = NULL;
                }
                else {
                    // node has one empty child
                    Node *child = node->left == NULL ? node->right : node->left;
                    if (parent->left == node) parent->left = child;
                    else parent->right = child;
                }
                delete node;
            }
        }
        else {
            // full node
            // find the min node of the right subtree
            Node *mi = find_min(node->right);
            Key k = mi->key;
            node->val = mi->val;
            removehelp(mi->key);
            node->key = k;
        }
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

    bool remove(const Key key) {
        if(find(key)) {
            removehelp(key);
            return true;
        }
        return false;
    }

    bool find(const Key key) {
        return findhelp(key, root) != NULL;
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
