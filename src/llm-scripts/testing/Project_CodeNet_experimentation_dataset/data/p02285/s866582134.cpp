#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n) ; i++)
constexpr auto INF = 2147483647;
typedef long long ll;

struct Node{
  int key;
  Node *right, *left, *parent;
};
//property
Node *root, *NIL;

void Insert(int k){
  Node *y = NIL;
  Node *x = root;
  Node *z;

  z= new Node;
  z ->key = k;
  z ->left = NIL;
  z ->right = NIL;

  while(x != NIL){
    y = x;
    if(z->key < x->key) x= x->left;
    else x = x-> right;
  }
  z->parent =y;
  if(y == NIL) root = z;
  else {
    if(z->key < y->key) y->left = z;
    else y->right = z;
  }
}

Node* Find(int k){
  Node *x = root;
  while (x != NIL){
    if(x->key == k) break;
    else if (k < x->key) x = x->left;
    else x = x->right;
  }
  return x;
}


//return minimum key node under x
Node* TreeMinimum(Node* x){
  while(x->left != NIL) x= x->left;
  return x;
}
//
Node* TreeSuccessor(Node* x){
  if(x->right!= NIL)return TreeMinimum(x->right);
  Node* y = x->parent;
  while( y != NIL && x== y->right){
    x= y;
    y = y->parent;
  }
  return y;
}

void Delete(Node* z){
  Node* y; // Delete comp
  Node* x; // child
  if(z->left == NIL || z->right ==NIL) y = z;
  else y = TreeSuccessor(z);
  
  if(y->left != NIL) x = y->left;
  else x= y-> right;
  if(x != NIL) x->parent = y->parent;
  if(y ==  y->parent->left) y->parent->left = x;
  else y->parent->right = x;
  
  if(y != z) z->key = y->key;
  free(y);
}

void Inorder(Node *r){
  if(r == NIL) return;
  Inorder(r->left);
  cout << " " << r->key;
  Inorder(r->right);
}

void Preorder(Node *r){
  if(r == NIL) return;
  cout << " " << r->key;
  Preorder(r->left);
  Preorder(r->right);
}


int main(){

  int m, k;
  string com;
  cin >> m;
  rep(i,m){
    cin >> com;
    if(com == "print"){
      Inorder(root);
      cout << endl;
      Preorder(root);
      cout << endl;
    }else{
      cin >> k;
      if (com == "insert"){
      Insert(k);  
    }else if(com == "find"){
      Node* u = Find(k);
      if(u != NIL) cout << "yes" << endl;
      else cout << "no" << endl;
    }else if(com == "delete"){
      Delete(Find(k));
    }
    }
    
    
  }

  return 0;
}
