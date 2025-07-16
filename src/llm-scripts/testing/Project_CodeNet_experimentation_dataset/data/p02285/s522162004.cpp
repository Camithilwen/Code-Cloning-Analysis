#include <iostream>
using namespace std;

struct Node {
    Node *parent;
    Node *left;
    Node *right;
    int key;
};

Node *NIL, *root;

void init() {
    root = NIL;
}

void insert(int key) {
    Node *y = NIL;
    Node *x = root;
    while (x != NIL) {
        y = x;
        if (key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    Node *node = (Node *)malloc(sizeof(Node));
    node->parent = y;
    node->key = key;
    node->left = NIL;
    node->right = NIL;
    if (y == NIL) {
        root = node;
    } else if (key < y->key) {
        y->left = node;
    } else {
        y->right = node;
    }
}

Node* find(int key) {
    Node *x = root;
    while (x != NIL && x->key != key) {
        if (key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    return x;
}

void attachNodeToParent(Node *node, Node *attached) {
    if (node->parent->left == node) {
        node->parent->left = attached;
    } else {
        node->parent->right = attached;
    }
}

Node* findNextNode(Node *node) {
    Node *x;
    if (node->right != NIL) {
        x = node->right;
        while(x->left != NIL) {
            x = x->left;
        }
    } else {
        Node *y = node;
        x = node->parent;
        while(y == x->right) {
            y = x;
            x = x->parent;
        }
    }

    return x;
}

void deleteNode(Node *node) {
    if (node == NIL) {
        return;
    }

    Node *deleted;
    if (node->left == NIL || node->right == NIL) {
        deleted = node;
    } else {
        deleted = findNextNode(node);
    }

    Node *child;
    if (deleted->left != NIL) {
        child = deleted->left;
    } else {
        child = deleted->right;
    }

    if (child != NIL) {
        child->parent = deleted->parent;
    }

    if (deleted->parent == NIL) {
        root = child;
    } else if (deleted->parent->left == deleted) {
        deleted->parent->left = child;
    } else {
        deleted->parent->right = child;
    }

    if (deleted != node) {
        node->key = deleted->key;
    }

    free(deleted);
}

void printByPreorder(Node *node) {
    if (node == NIL) {
        return;
    }

    cout << " "<< node->key;
    printByPreorder(node->left);
    printByPreorder(node->right);
}

void printByInorder(Node *node) {
    if (node == NIL) {
        return;
    }

    printByInorder(node->left);
    cout << " "<< node->key;
    printByInorder(node->right);
}

int main() {
    int n;
    cin >> n;

    init();

    string command;
    int key;
    for (int i = 0; i < n; i++) {
        cin >> command;
        if (command == "insert") {
            cin >> key;
            insert(key);
        } else if (command == "find") {
            cin >> key;
            Node *node = find(key);
            if (node != NIL) cout << "yes" << endl;
            else cout << "no" << endl;
        } else if (command == "delete") {
            cin >> key;
            Node *node = find(key);
            deleteNode(node);
        } else {
            printByInorder(root);
            cout << endl;
            printByPreorder(root);
            cout << endl;
        }
    }

    return 0;
}

