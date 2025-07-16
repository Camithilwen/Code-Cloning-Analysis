#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

struct Node {
    int key;
    Node *left, *right, *parent;
};
Node *root, *NIL;

void insert(int k) {
    if(root == NIL) {
        root = (Node *)malloc(sizeof(Node));
        root->key = k;
        root->left = root->right = NIL;
    }else {
        Node *z = (Node *)malloc(sizeof(Node));
        z->key = k;
        z->left = z->right = NIL;

        Node *x = root;
        while(true) {
            if(k < x->key) {
                if(x->left == NIL) {
                    x->left = z;
                    z->parent = x;
                    break;
                }
                else x = x->left;
            }else {
                if(x->right == NIL) {
                    x->right = z;
                    z->parent = x;
                    break;
                }
                else x = x->right;
            }
        }
    }
}

Node *find(Node *node, int k) {
    Node *x = node;
    while(x != NIL && k != x->key) {
        if(k < x->key) x = x->left;
        else x = x->right;
    }

    return x;
}

Node *treeSuccessor(Node *x) {
    if(x->right != NIL) {
        x = x->right;
        while(x->left != NIL) x = x->left;
        return x;
    }
    /*else {
        Node *y = x->parent;
        while(y!=NIL && x==y->right) {
            x = y;
            y = y->parent;
        }
        return y;
    }
    */

}

void deleteNode(Node *node) {
    Node *target, *child;
    if(node->left == NIL || node->right == NIL) target = node;
    else target = treeSuccessor(node);

    if(target->left != NIL)
        child = target->left;
    else
        child = target->right;
    if(child != NIL) child->parent = target->parent;

    if(target->parent == NIL) root = child;
    else {
        if(target == target->parent->left)
            target->parent->left = child;
        else
            target->parent->right = child;
    }

    if(target != node) node->key = target->key;
    free(target);
}

void inorder(Node *node) {
    if(node == NIL) return;
    inorder(node->left);
    printf(" %d", node->key);
    inorder(node->right);
}

void preorder(Node *node) {
    if(node == NIL) return;
    printf(" %d", node->key);
    preorder(node->left);
    preorder(node->right);
}

int main()
{
    int n, x;
    char str[19];
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        if(str[0] == 'i') { //insert
            scanf("%d", &x);
            insert(x);
        }else if(str[0] == 'p') { //print
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }else if(str[0] == 'f') { //find
            scanf("%d", &x);
            Node *t = find(root, x);
            if(t != NIL) printf("yes\n");
            else printf("no\n");
        }else if(str[0] == 'd') { //delete
            scanf("%d", &x);
            deleteNode(find(root,x));
        }

    }

    return 0;
}