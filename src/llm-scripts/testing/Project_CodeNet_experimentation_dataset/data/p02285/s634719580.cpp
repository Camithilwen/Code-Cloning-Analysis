#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct node {
    int key;
    struct node *parent;
    struct node *left;
    struct node *right;
} Tree;
 
Tree *root, *nil;
 
void insert(int key);
Tree *findNode(Tree *node, int key);
bool isFindTree(Tree *node, int key);
Tree *findMaximumTree(Tree *node);
Tree *treeSuccessor(Tree *node);
void treeDelete(Tree *z);
void preorder(Tree *node);
void inorder(Tree *node);

int main() {
    int n, key, i;
    string command;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> command;
        if (command[0] == 'i') {
            cin >> key;
            insert(key);
        }
        else if (command[0] == 'd') {
            cin >> key;
            treeDelete(findNode(root, key));
        }
        else if (command[0] == 'f') {
            cin >> key;
            if (isFindTree(root, key)) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
        else if (command[0] == 'p') {
            inorder(root); cout << endl;
            preorder(root); cout << endl;
        }
    }

    return 0;
}

void insert(int key) {
    Tree *y = nil;
    Tree *x = root;
    Tree *z = (struct node*)malloc(sizeof(struct node));
    z->key = key;
    z->left = nil;
    z->right = nil;
    while (x != nil) {
        y = x;
        if (key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    };
    z->parent = y;
    if (y == nil) {
        root = z;
        return;
    }
    if (key <= y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
}


Tree *findNode(Tree *node, int key) {
    Tree* target = node;
    while (target != nil && target->key != key) {
        if (key < target->key) {
            target = target->left;
        } else {
            target = target->right;
        }
    }
    return target;
}

bool isFindTree(Tree *node, int key) {
    return findNode(node, key) != nil;
}

Tree *findMaximumTree(Tree *node) {
    while (node->left != nil) {
        node = node->left;
    }
    return node;
}

Tree *treeSuccessor(Tree *node) {
    if (node->right != nil) {
        return findMaximumTree(node->right);
    }
    Tree *y = node->parent;
    while (y != nil && node == y->right) {
        node = y;
        y = y->parent;
    }
    return y;
}
 
void treeDelete(Tree *z) {
    Tree *y, *key;
    if (z->left == nil || z->right == nil) y = z;
    else y = treeSuccessor(z);
    if (y->left != nil) {
        key = y->left;
    } else {
        key = y->right;
    }
    if (key != nil) {
        key->parent = y->parent;
    }
    if (y->parent == nil) {
        root = key;
    } else {
        if (y == y->parent->left) {
            y->parent->left = key;
        } else {
            y->parent->right = key;
        }
    }
    if (y != z) {
        z->key = y->key;
    }
}

void preorder(Tree *node) {
    if (node == nil) return;
    cout << " " << node->key;
    preorder(node->left);
    preorder(node->right);
}

void inorder(Tree *node) {
    if (node == nil) return;
    inorder(node->left);
    cout << " " << node->key;
    inorder(node->right);
}


