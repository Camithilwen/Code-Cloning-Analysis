#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node *parent, *left, *right;
};

Node *NIL, *root;

void insert(int x) {
    Node *p = NIL;
    Node *u = root;
    Node *in = (Node *)malloc(sizeof(Node));
    in->key = x;
    in->left = NIL;
    in->right = NIL;

    while (u != NIL) {
        p = u;
        if (in->key < u->key) {
            u = u->left;
        } else {
            u = u->right;
        }
    }

    in->parent = p;
    if (p == NIL) {
        root = in;
    } else if (in->key < p->key) {
        p->left = in;
    } else {
        p->right = in;
    }
}

bool find(Node *u, int x) {
    while (u != NIL && u->key != x) {
        if (x < u->key) {
            u = u->left;
        } else {
            u = u->right;
        }
    }

    if (u == NIL) {
        return false;
    } else {
        return true;
    }
}

Node * findP(Node *u, int x) {
    while (u != NIL && u->key != x) {
        if (x < u->key) {
            u = u->left;
        } else {
            u = u->right;
        }
    }

    return u;
}

Node * getMinimum(Node *u) {
    while (u->left != NIL) {
        u = u->left;
    }

    return u;
}

Node * getSuccessor(Node *u) {
    if (u->right != NIL) {
        return getMinimum(u->right);
    }

    Node *d = u->parent;
    while (d != NIL && u == d->right) {
        u = d;
        d = d->parent;
    }

    return d;
}

void deleteNode(Node *u) {
    Node *d, *x;
    if (u->left == NIL || u->right == NIL) {
        d = u;
    } else {
        d = getSuccessor(u);
    }

    if (d->left != NIL) {
        x = d->left;
    } else {
        x = d->right;
    }

    if (x != NIL) {
        x->parent = d->parent;
    }

    if (d->parent == NIL) {
        root = x;
    } else if (d == d->parent->left) {
        d->parent->left = x;
    } else {
        d->parent->right = x;
    }

    if (d != u) {
        u->key = d->key;
    }
}

void printPre(Node *u) {
    if (u == NIL) {
        return;
    }

    printf(" %d", u->key);
    printPre(u->left);
    printPre(u->right);
}

void printIn(Node *u) {
    if (u == NIL) {
        return;
    }

    printIn(u->left);
    printf(" %d", u->key);
    printIn(u->right);
}

int main() {
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        string com;
        cin >> com;
        if (com == "insert") {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (com == "find") {
            int x;
            scanf("%d", &x);
            if (find(root, x)) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        } else if (com == "delete") {
            int x;
            scanf("%d", &x);
            auto u = findP(root, x);
            deleteNode(u);
        } else {
            printIn(root);
            printf("\n");
            printPre(root);
            printf("\n");
        }
    }

    return 0;
}
