#include <cstdio>
#include <cstdlib>

typedef struct node {
    long v;
    node *parent;
    node *left;
    node *right;
} Node;

typedef struct {
    Node *root;
} Tree;

Tree T = {NULL};

void insertTree(Node *node) {
    Node *y = NULL;
    Node *x = T.root;
    while (x != NULL) {
        y = x;
        if (node->v < x->v) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    node->parent = y;
    if (y == NULL) {
        T.root = node;
    } else if (node->v < y->v) {
        y->left = node;
    } else {
        y->right = node;
    }
}

Node * find(long v) {
    Node *x = T.root;
    while (x != NULL) {
        if (x->v == v) return x;
        else if (x->v < v) x = x->right;
        else x = x->left;
    }
    return NULL;
}

void Transplant(Node *u, Node *v) {
    if (u->parent == NULL) {
        T.root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != NULL) {
        v->parent = u->parent;
    }
}

Node *TreeMinimum(Node *x) {
    while (x->left != NULL) {
        x = x->left;
    }
    return x;
}

void deleteNode(Node *z) {
    if (z->left == NULL) {
        Transplant(z, z->right);
    } else if (z->right == NULL) {
        Transplant(z, z->left);
    } else {
        Node *y = TreeMinimum(z->right);
        if (y->parent != z) {
            Transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        Transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
    }
}

void Preorder(Node *n) {
    if (n != NULL) {
        printf(" %ld", n->v);
        Preorder(n->left);
        Preorder(n->right);
    }
}

void Inorder(Node *n) {
    if (n != NULL) {
        Inorder(n->left);
        printf(" %ld", n->v);
        Inorder(n->right);
    }
}

int main () {
    long n;
    scanf("%ld", &n);
    char command[10];
    long value;
    for (long i=0; i<n; i++) {
        scanf(" %s %ld", command, &value);
        if (command[0] == 'i') {
            Node *node = (Node *)malloc(sizeof(Node));
            node->v = value;
            node->parent = NULL;
            node->left = NULL;
            node->right = NULL;
            insertTree(node);
        } else if (command[0] == 'f') {
            Node *found = find(value);
            if (found != NULL) printf("yes\n");
            else printf("no\n");
        } else if (command[0] == 'd') {
            Node *z = find(value);
            deleteNode(z);
        } else {
            Inorder(T.root);
            printf("\n");
            Preorder(T.root);
            printf("\n");
        }
    }

    return 0;
}