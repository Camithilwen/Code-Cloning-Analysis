///
// File:  alds1_8_c.cpp
// Author: ymiyamoto
//
// Created on Sun Oct 15 01:12:42 2017
//
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct tree_t {
  tree_t *left;
  tree_t *right;
  tree_t *parent;
  int64_t value;
  tree_t(tree_t *par, int64_t val)
  {
    left = NULL;
    right = NULL;
    parent = par;
    value = val;
  }
};

static tree_t *tree;
static vector<int64_t> pre, in;

void insert(tree_t *top, int64_t val)
{
  if (top == NULL) {
    tree = new tree_t(NULL, val);
    return;
  }

  if (val < top->value) {
    if (top->left == NULL) {
      tree_t *node = new tree_t(top, val);
      top->left = node;
    } else {
      insert(top->left, val);
    }
  } else if (val > top->value) {
    if (top->right == NULL) {
      tree_t *node = new tree_t(top, val);
      top->right = node;
    } else {
      insert(top->right, val);
    }
  }
}

void walk(tree_t *top)
{
  if (top == NULL) return;

  pre.push_back(top->value);
  walk(top->left);
  in.push_back(top->value);
  walk(top->right);
}

void print()
{
  pre.clear();
  in.clear();
  walk(tree);
  for (uint32_t i = 0; i < in.size(); i++) {
    cout << " " << in[i];
  }
  cout << endl;

  for (uint32_t i = 0; i < pre.size(); i++) {
    cout << " " << pre[i];
  }
  cout << endl;
}

bool find(tree_t *top, int64_t val)
{
  if (top == NULL)
    return false;
  else {
    if (val == top->value) {
      return true;
    } else if (val < top->value) {
      return find(top->left, val);
    } else {
      return find(top->right, val);
    }
  }
}

int64_t find_min(tree_t *top)
{
  if (top->left == NULL)
    return top->value;
  else
    return find_min(top->left);
}

void del(tree_t *top, int64_t val)
{
  if (val == top->value) {
    if (top->left == NULL && top->right == NULL) {
      tree_t *parent = top->parent;
      if (parent->left == top) {
        parent->left = NULL;
      } else {
        parent->right = NULL;
      }
      delete top;
    } else if (top->left == NULL) {
      tree_t *parent = top->parent;
      if (parent->left == top) {
        parent->left = top->right;
      } else {
        parent->right = top->right;
      }
      top->right->parent = parent;
      delete top;
    } else if (top->right == NULL) {
      tree_t *parent = top->parent;
      if (parent->left == top) {
        parent->left = top->left;
      } else {
        parent->right = top->left;
      }
      top->left->parent = parent;
      delete top;
    } else {
      top->value = find_min(top->right);
      del(top->right, top->value);
    }
  } else if (val < top->value) {
    del(top->left, val);
  } else {
    del(top->right, val);
  }
}

int32_t main()
{
  uint32_t n;
  cin >> n;

  for (uint32_t i = 0; i < n; i++) {
    string str;
    int64_t val;
    cin >> str;
    if (str[0] == 'i') {
      cin >> val;
      insert(tree, val);
    } else if (str[0] == 'f') {
      cin >> val;
      if (find(tree, val)) {
        cout << "yes" << endl;
      } else {
        cout << "no" << endl;
      }
    } else if (str[0] == 'd') {
      cin >> val;
      del(tree, val);
    } else {
      print();
    }
  }

  return 0;
}