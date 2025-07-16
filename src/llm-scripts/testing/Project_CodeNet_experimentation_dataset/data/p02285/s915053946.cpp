#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;

struct Node {
  int key;
  Node *parent, *left, *right;
};

Node* NIL;

int m;
Node* root;

void init() {
  NIL = new Node;
  NIL->parent = NIL;
  NIL->left = NIL;
  NIL->right = NIL;
  root = NIL;
}

void insert(int k) {
  Node* z = new Node {k, NIL, NIL, NIL};
  Node* y = NIL;
  Node* x = root;
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

void preParse(Node* u) {
  if (u == NIL) return;
  cout << " " << u->key;
  preParse(u->left);
  preParse(u->right);
}

void inParse(Node* u) {
  if (u == NIL) return;
  inParse(u->left);
  cout << " " << u->key;
  inParse(u->right);
}

Node* find(int k) {
  Node* c = root;
  while (c != NIL) {
    if (c->key == k) return c;
    else if (k < c->key) c = c->left;
    else c = c->right;
  }
  return NIL;
}

Node* getMinimum(Node* x) {
  while (x->left != NIL) x = x->left;
  return x;
}

Node* getSucessor(Node* x) {
  if (x->right != NIL) return getMinimum(x->right);

  Node* y = x->parent;
  while (y != NIL && x == y->right) {
    x = y;
    y = y->parent;
  }
  return y;
}

void deleteNode(Node* z) {
  Node* y;
  if (z->left == NIL | z->right == NIL) y = z;
  else y = getSucessor(z);

  Node* x;
  if (y->left != NIL) x = y->left;
  else x = y->right;

  if (x != NIL) x->parent = y->parent;

  if (y->parent == NIL) {
    root = x;
  } else if (y == y->parent->left) {
    y->parent->left = x;
  } else {
    y->parent->right = x;
  }

  if (y != z) z->key = y->key;
}

int main() {
  cin >> m;
  rep(i, m) {
    string com;
    cin >> com;
    int key;
    if (com == "insert") {
      cin >> key;
      insert(key);
    } else if (com == "print") {
      inParse(root);
      cout << endl;
      preParse(root);
      cout << endl;
    } else if (com == "find") {
      cin >> key;
      if (find(key) != NIL) cout << "yes" << endl;
      else cout << "no" << endl;
    } else if (com == "delete") {
      cin >> key;
      deleteNode(find(key));
    } else {
      cout << "error" << endl;
    }
  }
  return 0;
}

