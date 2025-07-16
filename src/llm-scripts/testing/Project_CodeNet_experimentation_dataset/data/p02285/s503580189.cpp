#include <bits/stdc++.h>

using namespace std;

struct Node {
    int k;
    Node *p, *l, *r;
};

Node *NIL, *root;

void insert(int key) {
    Node *parent = NIL;
    Node *node = root;
    Node *target = (Node *)malloc(sizeof(Node));
    target->k = key;
    target->l = NIL;
    target->r = NIL;

    while(node != NIL) {
        parent = node;
        if(target->k < node->k) {
            node = node->l;
        } else {
            node = node->r;
        }
    }
    target->p = parent;
    if(parent == NIL) {
        root = target;
    } else {
        if(target->k < parent->k) {
            parent->l = target;
        } else {
            parent->r = target;
        }
    }
}

Node *findNode(int key) {
    Node *node = root;
    while(node != NIL) {
        if(key < node->k) {
            node = node->l;
        } else if(key > node->k) {
            node = node->r;
        } else {
            return node;
        }
    }
    return NIL;
}

Node *getSuccessor(Node *target) {
    if(target->r != NIL) {
        target = target->r;
        while(target->l != NIL) {
            target = target->l;
        }
        return target;
    }

    Node *parent = target->p;
    while(parent != NIL && target == parent->r) {
        target = parent;
        parent = parent->p;
    }
    return parent;
}

void deleteNode(int key) {
    Node *target = findNode(key);
    // error handling
    if(target == NIL)
        return;
    Node *deleteNode;
    Node *deleteNodeChild;
    Node *deleteNodeParent;
    // select node to delete.
    if(target->l == NIL || target->r == NIL) {
        deleteNode = target;
    } else {
        deleteNode = getSuccessor(target);
    }
    // select child node of node to delete.
    if(deleteNode->l != NIL) {
        deleteNodeChild = deleteNode->l;
    } else {
        deleteNodeChild = deleteNode->r;
    }

    // if node to delete has the children nodes.
    if(deleteNodeChild != NIL) {
        deleteNodeChild->p = deleteNode->p;
    }

    // if node to delete is root of tree.
    if(deleteNode->p == NIL) {
        root = deleteNodeChild;
        // confirm which is node to delete.
    } else if(deleteNode == deleteNode->p->l) {
        deleteNode->p->l = deleteNodeChild;
    } else {
        deleteNode->p->r = deleteNodeChild;
    }

    if(target != deleteNode) {
        target->k = deleteNode->k;
    }
}

void inorder(Node *node) {
    if(node == NIL)
        return;
    inorder(node->l);
    printf(" %d", node->k);
    inorder(node->r);
}

void preorder(Node *node) {
    printf(" %d", node->k);
    if(node->l != NIL) {
        preorder(node->l);
    }
    if(node->r != NIL) {
        preorder(node->r);
    }
}

bool find(int key) {
    Node *node = root;
    while(node != NIL) {
        if(key < node->k) {
            node = node->l;
        } else if(key > node->k) {
            node = node->r;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    int n, key;
    string com;
    NIL = (Node *)malloc(sizeof(Node));
    root = (Node *)malloc(sizeof(Node));
    root = NIL;
    root->p = NIL;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> com;
        if(com == "print") {
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        } else {
            scanf("%d", &key);
            if(com == "find") {
                if(find(key)) {
                    printf("yes\n");
                } else {
                    printf("no\n");
                }
            } else if(com == "insert") {
                insert(key);
            } else if(com == "delete") {
                deleteNode(key);
            }
        }
    }
}
