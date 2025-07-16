#include<iostream>
using namespace std;

struct Node {
    int key;
    Node* parent;
    Node* left;
    Node* right;
    Node(int key_in){
        key    = key_in;
        parent = NULL;
        left   = NULL;
        right  = NULL;
    }
};

class Tree {
    Node* root;
    void inorder(Node* n){
        if (n == NULL) return;
        inorder(n->left);
        cout << " " << n->key;
        inorder(n->right);
    }
    void preorder(Node* n){
        if (n == NULL) return;
        cout << " " << n->key;
        preorder(n->left);
        preorder(n->right);
    }
public:
    Tree(){
        root = NULL;
    }
    void insert(int key){
        Node* z = new Node(key);
        if (root == NULL) {
            root = z;
            return;
        }
        Node* x = root;
        while (1) {
            Node** child_p;
            if (key < x->key) {
                child_p = &(x->left);
            } else {
                child_p = &(x->right);
            }
            if (*child_p == NULL) {
                *child_p = z;
                z->parent = x;
                return;
            }
            x = *child_p;
        }
    }
    void print(){
        inorder(root);
        cout << endl;
        preorder(root);
        cout << endl;
    }
    Node* find(int key){
        for (Node* x = root; x != NULL;) {
            if (key == x->key) return x;
            if (key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }
        return NULL;
    }

    void delete_1_child(Node* x){
        Node* child;
        if (x->left == NULL && x->right == NULL) {
            child = NULL;
        } else if (x->left != NULL) {
            child = x->left;
        } else {
            child = x->right;
        }
        if (x == root) {
            root = child;
            delete x;
            return;
        }
        Node* p = x->parent;
        if (x == p->left) {
            p->left = child;
        } else {
            p->right = child;
        }
        if (child != NULL) {
            child->parent = x->parent;
        }
        delete x;
    }

    Node* next_node(Node* x){
        if (x->left == NULL) return x;
        return next_node(x->left);
    }

    void delete_(int key){
        Node* x = find(key);
        if (x == NULL) return;
        if (x->left == NULL || x->right == NULL) {
            delete_1_child(x);
            return;
        }
        Node* y = next_node(x->right);
        x->key = y->key;
        if (y->left == NULL || y->right == NULL) {
            delete_1_child(y);
            return;
        }

    }
};


int main(){
    int m;
    cin >> m;
    Tree T;
    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;
        if (str == "print") {
            T.print();
            continue;
        }
        int num;
        cin >> num;
        if (str == "insert") {
            T.insert(num);
            continue;
        }
        if (str == "find") {
            if (T.find(num) == NULL) {
                cout << "no" << endl;
            } else {
                cout << "yes" << endl;
            }
            continue;
        }
        if (str == "delete") {
            T.delete_(num);
        }
    }
    return 0;
}