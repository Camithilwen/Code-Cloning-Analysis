#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct Node{int key; Node *p,*l,*r;};
Node *null,*root;


void insert(int k){
Node *x,*y,*z;
	y=null;
	x=root;
	z=(Node*)malloc(sizeof(Node));
	z->key=k;
	z->l=null;
	z->r=null;
	while(x!=null){
	    y=x;
		if(z->key<x->key)
		x=x->l;
		else 
		x=x->r;
	}
	z->p=y;
	if(y==null)
	root=z;
	else if(z->key>y->key)
	y->r=z;
	else
	y->l=z;
}
void in_p(Node *u){
	if(u==null)
	return;
	in_p(u->l);
	printf(" %d",u->key);
	in_p(u->r);
}
void pre_p(Node *u){
	if(u==null)
	return ;
	printf(" %d",u->key);
	pre_p(u->l);
	pre_p(u->r);
}
void print(){
	in_p(root);
	printf("\n");
	pre_p(root);
	printf("\n");
}
bool find(Node *a,int k){
	if(a==null)
	return false;
	    else if(a->key==k)
		return true;
		else if(a->key>k)
	     find(a->l,k);
	    else 
	    find(a->r,k);
	}
	Node* getmin(Node *x){
	while(x->l!=null)
	x=x->l;
	return x;
}
Node* getS(Node *x){
	if(x->r!=null)
	return getmin(x->r);
	Node *y;
	y=x->p;
	while(y!=null&&x==y->r){
	x=y;
		y=y->p;
	}
	return y;
}

void Delete(int k){
Node *y,*z,*x;
	x=null;
	z=root;
	while(z->key!=k&&z!=null){
		if(k>z->key)
		z=z->r;
		else
		z=z->l;
	}
	if(z->l==null || z->r==null)
	y=z;
else 
	y=getS(z);
	if(y->l!=null)
	x=y->l;
	else
	x=y->r;
	if(x!=null)
	x->p=y->p;
	if(y->p==null)
	root=x;
	else if(y==y->p->l)
	y->p->l=x;
	else
	y->p->r=x;
	if(y!=z)
	z->key=y->key;
	free(y);
}

main(){
	int i,n,key;
	string com;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		cin>>com;
		if(com=="insert"){
			scanf("%d",&key);
			insert(key);
		}
		else if(com=="find"){
			scanf("%d",&key);
			if(find(root,key))
			printf("yes\n");
			else
			printf("no\n");
		}
		else if(com=="delete"){
			scanf("%d",&key);
			Delete(key);
		}
		else 
		print();
	}
	
	return 0;
}

