#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i = 0; i < n; i++)
typedef long long ll;
// Welcome to my source code!

struct Node {
    int key;
    Node *parent, *left, *right;
};

Node *root, *NIL;

void insertKey(int key) {
    Node *y = NIL;
    Node *x = root;
    Node *z;

    z = new Node;
    z->key = key;
    z->left = NIL;
    z->right = NIL;

    while (x != NIL) {
        y = x;
        if (z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;

    if (y == NIL) {
        root = z;
    } else {
        if (z->key < y->key) {
            y->left = z;
        } else {
            y->right = z;
        }
    }
}

Node* findKey(Node *u, int key) {
    while (u != NIL && u->key != key) {
        if (key < u->key) {
            u = u->left;
        } else {
            u = u->right;
        }
    }
    return u;
}

Node* getMinimum(Node *x) {
    while (x->left != NIL) x = x->left;
    return x;
}

Node* getSuccessor(Node *z) {
    if (z->right != NIL) return getMinimum(z->right);
    Node *y = z->parent;
    while (y != NIL && z == y->right) {
        z = y;
        y = y->parent;
    }
    return y;
}

Node* deleteNode(Node *z) {
    Node *y;
    Node *x;

    if (z->left == NIL || z->right == NIL) y = z;
    else y = getSuccessor(z);

    if (y->left != NIL) x = y->left;
    else x = y->right;

    if (x != NIL) x->parent = y->parent;

    if (y->parent == NIL) root = x;
    else if (y == y->parent->left) y->parent->left = x;
    else y->parent->right = x;

    if (y != z) z->key = y->key;
}

void inorder(Node *u) {
    if (u == NIL) return;
    inorder(u->left);
    printf(" %d", u->key);
    inorder(u->right);
}

void preorder(Node *u) {
    if (u == NIL) return;
    printf(" %d", u->key);
    preorder(u->left);
    preorder(u->right);
}

int main() {
    int m, k;
    string com;
    cin >> m;
    
    REP(i,m) {
        cin >> com;
        if (com == "print") {
            inorder(root);
            cout << '\n';
            preorder(root);
            cout << endl;
        } else {
            cin >> k;
            if (com == "insert") insertKey(k);
            else if (com == "find") {
                if (findKey(root, k) != NIL) cout << "yes" << endl;
                else cout << "no" << endl;
            } else {
                deleteNode(findKey(root, k));
            }
        }
    }
}
