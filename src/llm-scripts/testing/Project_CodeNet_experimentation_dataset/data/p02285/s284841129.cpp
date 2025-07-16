#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
struct node{
    int key;
    node *parent,*left,*right;
};
node *NIL,*root;
 
void inorder(struct node *u){
    if(u==NIL)return;
    inorder(u->left);
    printf(" %d",u->key);
    inorder(u->right);
}
void preorder(struct node *u){
    if(u==NIL)return;
    printf(" %d",u->key);
    preorder(u->left);
    preorder(u->right);
}
void pr(){
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
}
void insert(int key){
    node *y = NIL;
    node *x = root;
    node *z;
    z = (node *)malloc(sizeof(node));
    z->key = key;
    z->left = NIL;
    z->right = NIL;
     
    while(x!=NIL){//when x==NIL break
        y = x;
        if(z->key < x->key)x = x->left;
        else x = x->right;
    }
    z->parent = y;
    if(y == NIL)root = z;//z became root,insert root
    else if(z->key < y->key)y->left = z;
    else y->right = z;
}
node * find(node *u,int k){
    while((u != NIL) && (k != u->key)){  
    //when you exchange the position of '(u != NIL)' with '(k != u->key)',the program will run failed
    //you must make sure that u!=NIl firstly,otherwise k will compare with NIL->key(which is not defined)
        if(k < u->key)u = u->left;
        else u = u->right;
    }
    return u;
}
node * treeMinmum(node *x){
	while(x->left!=NIL)x = x->left;//"leftmost"
	return x;
}
node * treeSuccessor(node *x){
	if(x->right != NIL)return treeMinmum(x->right);//exist right tree,find the next node inorder
	
	node *y = x->parent;//not exist,return parent node which acts as left-child node firstly
	while(y!=NIL && y->right == x){
		x = y;
		y = y->parent;
	}
	return y;
}
void treedelete(node *z){
	node *y;//the node to delete
	node *x;//child-node of the node needed to be deleted
	
	//make sure wheter z delete or not
	if(z->left == NIL || z->right == NIL)y = z;
	else y = treeSuccessor(z);
	
	if(y->left != NIL)x = y->left;
	else x = y->right;
	
	if(x != NIL )x->parent = y->parent; // make y->parent as x new parent
	
	// make x as y->parent new child
	if(y->parent == NIL)root = x;//y was root
	else if(y == y->parent->left)y->parent->left = x;
	else y->parent->right = x;
	
	
	if(y!=z)z->key = y->key;
	free(y);
}
int main()
{
    int n,k;
    scanf("%d",&n);
    char s[20];
    for(int i=0;i<n;++i){
        scanf("%s",s);
        if(s[0]=='i'){
            scanf("%d",&k);
            insert(k);
        }else if(s[0]=='f'){
            scanf("%d",&k);
            node *t = find(root,k);
            if(t != NIL )printf("yes\n");
            else printf("no\n");
        }
        else if(s[0]=='d'){
        	scanf("%d",&k);
        	treedelete(find(root,k));
		}
		else pr();
    }
    return 0;
}