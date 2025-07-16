#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <sstream>
#include <string>
#include <utility>
#include <map>
#include <memory>
#include <set>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>

using namespace std;

struct Node
{
  Node *parent;
  Node *left;
  Node *right;
  int key;
};

class BStree
{
public:
  Node *root;
  Node *nil;
  int solve();
  int print();
  int insert( Node *z );
  int preorder( Node *nd );
  int inorder( Node *nd );
  Node* find( int k );
  Node* next( Node *nd );
  int delete_node( Node *nd );
};

int BStree::solve()
{
  int n;
  cin >> n;
  
  string com;
  int d;
  Node *nd;
  
  for ( auto i = 0; i < n; ++i )
    {
      cin >> com;

      if ( com == "print" )
        print();
      else if ( com == "insert" )
        {
          cin >> d;
          nd = new Node;
          nd->key = d;
          nd->parent = nil;
          nd->left = nil;
          nd->right = nil;
          insert( nd );
        }
      else if ( com == "find" )
        {
          cin >> d;
          if ( find( d ) == nil )
            cout << "no" << endl;
          else
            cout << "yes" << endl;
        }
      else
        {
          cin >> d;
          Node *x = find( d );
          if ( x != nil )
            {
              delete_node( x );
            }
        }
    }
      
  return 0;
}

int BStree::print()
{
  inorder( root );
  cout << endl;
  preorder( root );
  cout << endl;
  return 0;
}

int BStree::insert( Node *z )
{
  Node *y = nil;
  Node *x = root;

  while ( x != nil )
    {
      y = x;
      if ( z->key < x->key )
        x = x->left;
      else
        x = x->right;
    }

  z->parent = y;

  if ( y == nil )
    root = z;
  else if ( z->key < y->key )
    y->left = z;
  else
    y->right = z;
  
  return 0;
}

Node* BStree::find( int k )
{
  Node *x;
  x = root;
  
  while ( x != nil )
    {
      if ( x->key == k )
        return x;
      else if ( x->key > k )
        x = x->left;
      else
        x = x->right;
    }

  return x;
}

Node* BStree::next( Node *nd )
{
  Node *x;
  x = nd->right;
  while ( x->left != nil )
    {
      x = x->left;
    }
  return x;
}

int BStree::delete_node( Node *nd )
{
  if ( nd == nil )
    return 0;

  if ( nd->left == nil && nd->right == nil )
    {
      if ( nd->parent->left == nd )
        nd->parent->left = nil;
      else
        nd->parent->right = nil;

      delete nd;
    }
  else if ( nd->left == nil )
    {
      if ( nd->parent->left == nd )
        nd->parent->left = nd->right;
      else
        nd->parent->right = nd->right;
      
      nd->right->parent = nd->parent;

      delete nd;
    }
  else if ( nd->right == nil )
    {
      if ( nd->parent->left == nd )
        nd->parent->left = nd->left;
      else
        nd->parent->right = nd->left;

      nd->left->parent = nd->parent;
      
      delete nd;
    }
  else
    {
      Node *x = next( nd );

      nd->key = x->key;

      delete_node( x );
    }
      
  return 0;
}

int BStree::preorder( Node *nd )
{
  if ( nd == nil )
    return 0;

  cout << " " << nd->key;
  preorder( nd->left );
  preorder( nd->right );
  
  return 0;
}

int BStree::inorder( Node *nd )
{
  if ( nd == nil )
    return 0;

  inorder( nd->left );
  cout << " " << nd->key;
  inorder( nd->right );
  
  return 0;
}

int main()
{

  BStree b;

  b.nil = new Node;
  b.nil->parent = b.nil;
  b.nil->left = b.nil;
  b.nil->right = b.nil;
  b.nil->key = -1;

  b.root = b.nil;
  
  b.solve();

  return 0;
}