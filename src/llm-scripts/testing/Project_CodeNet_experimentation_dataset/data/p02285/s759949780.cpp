#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct node{
	int num;
	node *parent,*left,*right;
};
node *root,*NIL;

node *treemin(node *x){
	while(x->left!=NIL)
		x=x->left;
	return x;
}

node *nextnode(node *x){
	if(x->right!=NIL) return treemin(x->right);
	node *y=x->parent;
	while(y!=NIL && x==y->right){
		x=y;
		x=y->parent;
	}
	return y;
}

void denode(node *z){
	node *x,*y;
	if(z->left==NIL||z->right==NIL) y=z;
	else y=nextnode(z);
	if(y->left!=NIL) x=y->left;
	else x=y->right;
	if(x!=NIL) x->parent=y->parent;
	if(y->parent==NIL) root=x;
	else{
		if(y==y->parent->left) y->parent->left=x;
		else y->parent->right=x;
	}
	if(y!=z) z->num=y->num;
//	denode(y);
	return ;
}

node *find(int a){
	node *x=root;
	while(x!=NIL){
		if(x->num<a) x=x->right;
		else if(x->num>a) x=x->left;
		else return x;
	}
	return NIL;
}

void print_inorder(node *x){
	if(x==NIL) return ;
	print_inorder(x->left);
	printf(" %d",x->num);
	print_inorder(x->right);
	return ;
}

void print_preorder(node *x){
	if(x==NIL) return ;
	printf(" %d",x->num);
	print_preorder(x->left);
	print_preorder(x->right);
	return ;
}

void insert(int a){
	node *x=root,*y=NIL;
	node *z=new node();
	z->num=a;z->left=NIL;z->right=NIL;
	while(x!=NIL){
		y=x;
		if(z->num < x->num) x=x->left;
		else x=x->right;
	}
	z->parent=y;
	if(y==NIL) root=z;
	else {
		if(z->num < y->num) y->left=z;
		else y->right=z;
	}
	return ;
}

int main(){
	int n;
	cin>>n;
	string s;
	node *f;
	int a;
	for(int i=0;i<n;i++){
		cin>>s;
		if(s[0]=='i') cin>>a,insert(a);
		else if(s[0]=='p'){
			print_inorder(root);
			printf("\n");
			print_preorder(root);
			printf("\n");
		}
		else if(s[0]=='f'){
			cin>>a;
			f=find(a);
			if(f==NIL) printf("no\n");
			else printf("yes\n");
		}
		else{
			cin>>a;
			denode(find(a));
		}
	}
	return 0;
}
