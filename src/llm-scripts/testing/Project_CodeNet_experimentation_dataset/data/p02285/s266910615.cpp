#include <bits/stdc++.h>
using namespace std;

struct Node{
  int key;
  Node *right,*left,*parent;
};

Node *root,*NIL;

Node * Min(Node *p){
  while(p->left!=NIL) p=p->left;
  return p;
}

Node * find(Node *p,int a){
  while(p!=NIL && a!=p->key){
    if(a<p->key) p=p->left;
    else p=p->right;
  }
  return p;
}

Node * Successor(Node *p){
  if(p->right!=NIL) return Min(p->right);
  Node *q=p->parent;
  while(q!=NIL && p==q->right){
    p=q;
    q=q->parent;
  }
  return q;
}

Node * Delete(Node *p){
  Node *a,*b;

  if(p->left==NIL || p->right==NIL) b=p;
  else b=Successor(p);

  if(b->left!=NIL) a=b->left;
  else a=b->right;

  if(a!=NIL) a->parent=b->parent;
  if(b->parent==NIL) root=a;
  else if(b==b->parent->left) b->parent->left=a;
  else b->parent->right=a;

  if(b!=p) p->key=b->key;

  free(b);
}

void insert(int a){
  Node *y=NIL, *x=root, *z;
  z = (Node *)malloc(sizeof(Node));
  z->key=a;
  z->left=NIL;
  z->right=NIL;

  while(x!=NIL){
    y=x;
    if(z->key<x->key) x=x->left;
    else x=x->right;
  }
  z->parent=y;
  if(y==NIL) root=z;
  else if(z->key<y->key) y->left=z;
  else y->right=z;
}

void inorder(Node *p){
  if(p==NIL) return;
  inorder(p->left);
  cout << " " << p->key;
  inorder(p->right);
}

void preorder(Node *p){
  if(p==NIL) return;
  cout << " " << p->key;
  preorder(p->left);
  preorder(p->right);
}

int main(){
  int n,x;
  string str;
  cin >> n;

  for(int i=0;i<n;i++){
    cin >> str;
    if(str=="find"){
      cin >> x;
      Node *p=find(root,x);
      if(p!=NIL) cout << "yes" << endl;
      else cout << "no" << endl;
    }
    else if(str=="insert"){
      cin >> x;
      insert(x);
    }
    else if(str=="print"){
      inorder(root);
      cout << endl;
      preorder(root);
      cout << endl;
    }
    else if(str=="delete"){
      cin >> x;
      Delete(find(root,x));
    }
  }
  return 0;
}
