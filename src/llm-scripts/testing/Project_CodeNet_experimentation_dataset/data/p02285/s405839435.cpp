#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
using namespace std;

struct Node{
	int key;
	Node *parent, *left, *right;
};

Node *root, *NIL;

void insert(int k){
	Node *y = NIL;
	Node *x = root;
	Node *z;
	
	z = (Node *)malloc(sizeof(Node));
	z->key = k;
	z->left = NIL;
	z->right = NIL;
	
	while(x != NIL){
		y = x;
		if(z->key < x->key){
			x = x->left;
		} else {
			x = x->right;
		}
	}
	z->parent = y;
	if( y == NIL){
		root = z;
	} else {
		if(z->key < y->key){
			y->left = z;
		} else {
			y->right = z;
		}
	}
}

bool find(int k, Node *u){
	if(u == NIL) return false;
	if(u->key == k) return true;
	return (u->key > k)?find(k,u->left):find(k,u->right);
}

Node * treeMinimum(Node *x){
	while(x->left != NIL) x = x->left;
	return x;
}

Node * _find(Node *u, int k){
	while(u != NIL && k != u->key){
		if(k < u->key) u = u ->left;
		else u = u->right;
	}
	return u;
}

Node * treeSuccessor(Node * x){
	if(x->right != NIL) return treeMinimum(x->right);
	Node  *y = x->parent;
	while(y != NIL && x == y->right){
		x = y;
		y = y->parent;
	}
	return y;
}
void treeDelete(Node *z){
	Node *y;
	Node *x;
	
	if(z->left == NIL  || z->right == NIL) y = z;
	else y = treeSuccessor(z);
	
	if(y->left != NIL){
		x = y->left;
	} else {
		x = y->right;
	}
	
	if(x != NIL){
		x->parent = y->parent;
	}
	
	if(y->parent == NIL){
		root = x;
	} else {
		if(y == y->parent->left){
			y->parent->left = x;
		} else {
			y->parent->right = x;
		}
	}
	
	if(y != z){
		z->key = y->key;
	}
	
	free(y);
}

void inorder(Node *u){
	if( u == NIL) return;
	inorder(u->left);
	printf(" %d", u->key);
	inorder(u->right);
}

void preoder(Node *u){
	if( u == NIL) return;
	printf(" %d", u->key);
	preoder(u->left);
	preoder(u->right);
}

int main(){
	int n;
	string s;
	
	cin>>n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		// scanf("%s", s);
		cin>>s;
		if(s == "print"){
			inorder(root);
			printf("\n");
			preoder(root);
			printf("\n");
		} else if(s == "insert"){
			int x;
			scanf("%d", &x);
			insert(x);
		} else if(s == "find"){
			int k;
			scanf("%d", &k);
			printf(("%s",find(k,root)?"yes":"no"));
			printf("\n");
		} else if(s == "delete"){
			int k;
			scanf("%d", &k);
			treeDelete(_find(root,k));
		}
	}
	
	return 0;
}
