#include <iostream>
#include <bits/stdc++.h>
#define MAX_SIZE 500010
#define INFTY 2000000000
using namespace std;

struct Node {
    int key;
    Node *parent, *left, *right;
};

Node *root, *NIL;

void insert(int k) {
    Node *z = (Node *)malloc(sizeof(Node));
    z->key = k;
    z->left = NIL;
    z->right = NIL;
    Node *y = NIL;
    Node *x = root;
    while (x != NIL) {
        y = x;
        if (z->key < x->key) x = x->left;
        else x = x->right;
    }
    z->parent = y;
    if (y == NIL) root = z;
    else if (z->key < y->key) y->left = z;
    else y->right = z;
}

Node *find(int k) {
    Node *x = root;
    while (x != NIL && k != x->key) {
        if (k < x->key) x = x->left;
        else x = x->right;
    }
    return x;
}

void replace(Node *x, Node *y, Node *z) {

}

Node *getMInimum(Node *x) {
    while (x->left != NIL) x = x->left;
    return x;
}

Node *getSuccessor(Node *x) {
    if (x->right != NIL) return getMInimum(x->right);
    Node *y = x->parent;
    while (y != NIL && x == y->right) {
        x = y;
        y = x->parent;
    }
    return y;
}

void deleteNode(Node *z) {
    Node *x, *y;
    if (z->left != NIL && z->right != NIL) y = getSuccessor(z);
    else y = z;
    if (y->left != NIL) x  = y->left;
    else x = y->right;

    if (x != NIL) x->parent = y->parent;

    if (y->parent == NIL) root = x;
    else if (y->parent->left == y) y->parent->left = x;
    else y->parent->right = x;
    if (y != z) z->key = y->key;
    free(y);
}



void findPrint(int k) {
    if (find(k) == NIL) printf("no\n");
    else printf("yes\n");
}

void preorder(Node* u) {
    if (u == NIL) return;
    printf(" %d", u->key);
    preorder(u->left);
    preorder(u->right);
}

void inorder(Node* u) {
    if (u == NIL) return;
    inorder(u->left);
    printf(" %d", u->key);
    inorder(u->right);    
}

void postorder(Node* u) {
    if (u == NIL) return;
    postorder(u->left);
    postorder(u->right);
    printf(" %d", u->key);
}

void print() {
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
}

int main(){
    int n, k;
    char cmd[10];
    root = NIL;
    cin >> n;
    for (int i=0; i < n; i++) {
        scanf("%s%d\n", cmd, &k);
        // cout << cmd << k << endl;
        if (cmd[0] == 'i') insert(k);
        else if (cmd[0] == 'f') findPrint(k);
        else if (cmd[0] == 'd') deleteNode(find(k));
        else if (cmd[0] == 'p') print();
    }
    return 0;
} 
