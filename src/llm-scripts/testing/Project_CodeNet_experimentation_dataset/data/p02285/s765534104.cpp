#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
public:
  int key;
  Node* parent;
  Node* left;
  Node* right;
  Node(int key) {
    this->key = key;
    this->parent = NULL;
    this->left = NULL;
    this->right = NULL;
  }
  void append_left(Node* left) {
    this->left = left;
  }
  void append_right(Node* right) {
    this->right = right;
  }
  void append_parent(Node* parent) {
    this->parent = parent;
  }
};

Node* root;

void insert(int key) {
  Node* z = new Node(key);
  Node* cur = root; Node* x = root;
  while(cur != NULL) {
    x = cur;
    if(z->key > cur->key)
      cur = cur->right;
    else
      cur = cur->left;
  }
  if(z->key > x->key) {
    x->append_right(z);
  }
  else {
    x->append_left(z);
  }
  z->append_parent(x);
}
Node* find(int key) {
  Node* z = root;
  while(z != NULL) {
    if(key == z->key)
      return z;
    else if(key > z->key)
      z = z->right;
    else
      z = z->left;
  }
  return NULL;
}
void delete_node(Node *z) {
  if(z==NULL) return;

  int degree = 0;
  if(z->left != NULL) degree++;
  if(z->right != NULL) degree++;

  if(degree == 0) {
    Node* parent = z->parent;
    if(parent == NULL) {
      delete z;
      root = NULL;
      return;
    }
    if(parent->left == z) parent->left = NULL;
    else parent->right = NULL;
    delete z;
  }
  else if(degree == 1) {
    Node* parent = z->parent;
    Node* child;
    if(z->left != NULL) child = z->left;
    else child = z->right;
    if(parent == NULL) {
      root = child;
      root->parent = NULL;
      delete z;
      return;
    }
    if(parent->left == z) parent->left = child;
    else parent->right = child;
    child->parent = parent;
    delete z;
    return;
  }
  else if(degree == 2) {
    Node *y = z->right;
    while(y->left != NULL) {
      y = y->left;
    }
    z->key = y->key;
    delete_node(y);
  }
  return;
}

void print_crawl_preorder(Node* node) {
  if(node == NULL) return;
  cout << " " << node->key;
  if(node->left != NULL) {
    print_crawl_preorder(node->left);
  }
  if(node->right != NULL) {
    print_crawl_preorder(node->right);
  }
  return;
}
void print_crawl_inorder(Node* node) {
  if(node == NULL) return;
  if(node->left != NULL) {
    print_crawl_inorder(node->left);
  }
  cout << " " << node->key;
  if(node->right != NULL) {
    print_crawl_inorder(node->right);
  }
  return;
}

int main() {
  int n; cin >> n;
  root = NULL;
  for(int i=0;i<n;i++) {
    string command; cin >> command;
    if(command == "insert") {
      int key; cin >> key;
      if(root == NULL) {
        root = new Node(key);
      }
      else {
        insert(key);
      }
    }
    else if(command == "find") {
      int key; cin >> key;
      if(find(key) != NULL) cout << "yes" << endl;
      else cout << "no" << endl;
    }
    else if(command == "delete") {
      int key; cin >> key;
      delete_node(find(key));
    }
    else if(command == "print") {
      print_crawl_inorder(root); cout << endl;
      print_crawl_preorder(root); cout << endl;
    }
  }
}