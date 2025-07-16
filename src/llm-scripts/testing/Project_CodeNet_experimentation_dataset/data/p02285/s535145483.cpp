#include <iostream>
#include <stdio.h>
#include <string.h>

#define MAX 100
//#define NIL -1

struct Node {
    int key;
    Node *parent, *left, *right;
};

Node *root, *NIL;
int n;

void insert(int val) {
    Node *y = NIL;
    Node *x = root;
    Node *z = new Node();
    
    z->key = val;
    z->left = NIL;
    z->right = NIL;
    
    while (x != NIL) {
        y = x;
        if (z->key > x->key) {
            x = x->right;
        } else {
            x = x->left;
        }
    }
    z->parent = y;
    
    if ( y == NIL ) {
        root = z;
    } else if ( y->key > z->key ) {
        y->left = z;
    } else {
        y->right = z;
    }
//    delete z;
}

Node * find(Node *x, int val) {
    while ( x != NIL) {
        if (x->key == val) break;
        if (x->key > val) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return x;
}


Node * getSuccessor(Node *u) {
    while (u->left != NIL) {
        u = u->left;
    }
    return u;
}


void delete_node(Node *u) {
    Node *y;
    Node *x;
    if (u->left != NIL && u->right != NIL) {
        y = getSuccessor(u->right);
    } else {
        y = u;
    }
    
    // search child
    if (y->left != NIL) {
        x = y->left;
    } else {
        x = y->right;
    }
    
    // set the parent to the child if it exists
    if (x != NIL) {
        x->parent = y->parent;
    }
    
    if ( y->parent == NIL ) {
        root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    
    if ( u != y ) {
        u->key = y->key;
    }
    
    delete y;
}

void preorder(Node *u) {
    if (u == NIL) return;
    
    printf(" %d", u->key);
    preorder(u->left);
    preorder(u->right);
}

void inorder(Node *u) {
    if (u == NIL) return;
    
    inorder(u->left);
    printf(" %d", u->key);
    inorder(u->right);
}

void print() {
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
}

int main() {
    int val;
    char moji[10];
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", moji);
        if (moji[0] == 'i') {
            scanf("%d", &val);
            insert(val);
        } else if (moji[0] == 'f') {
            scanf("%d", &val);
            Node *t = find(root, val);
            if ( t != NIL ) printf("yes\n");
            else printf("no\n");
        } else if (moji[0] == 'd') {
            scanf("%d", &val);
            Node *t = find(root, val);
            delete_node(t);
        } else {
            print();
        }
    }
    
    return 0;
}