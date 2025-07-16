#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;

struct node
{
    int key;
    node *parent,*left,*right;
    node():key(-1),parent(NULL),left(NULL),right(NULL) {}
};
node *root,*nil;

node* newnode()
{
    return new node();
}

void insert(int num)
{
    node* x=root;
    node* y=nil;
    node* z=newnode();
    z->key=num;
    while(x!=nil)
    {
        y=x;
        if(num>=x->key)
            x=x->right;
        else
            x=x->left;
    }
    if(y==nil) root=z;
    else
    {
        z->parent=y;
        if(num<y->key)
            y->left=z;
        else
            y->right=z;
    }
}

node* find(node* u,int num)
{
    while(u!=nil&&num!=u->key)
    {
        if(num< u->key) u=u->left;
        else u=u->right;
    }
    return u;
}

node* minele(node* u)
{
    while(u->left!=nil)
        u=u->left;
    return u;
}

node* nextpos(node* u)
{
//	node* y=nil;
//	if(u->right!=nil) y=minele(u->right);
//	else 														//?¬¬????????\???????????????????????°?????¶???????°±???u??????????????????
//	{
//		y=u->parent;
//		while(y!=nil&&y->right==u)
//		{
//			u=y;
//			y=y->parent;
//		}
//	}
//	return y;
    return minele(u->right);
}

void Delete(node* u)
{
    node* y;
    node* x;
    if(u->left==nil||u->right==nil) y=u;
    else y=nextpos(u);
    if(y->left!=nil) x=y->left;
    else x=y->right;

    if(x!=nil) x->parent=y->parent;

    if(y->parent==nil) root=x;
    else
    {
        if(y==y->parent->left) y->parent->left=x;
        else y->parent->right=x;
    }
    if(y!=u)
        u->key=y->key;
    delete y;
}

void inorder(node* u)
{
    if(u->left!=nil) inorder(u->left);
    printf(" %d",u->key);
    if(u->right!=nil) inorder(u->right);
    return;
}

void preorder(node* u)
{
    printf(" %d",u->key);
    if(u->left!=nil) preorder(u->left);
    if(u->right!=nil) preorder(u->right);
    return;
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; ++i)
    {
        char s[11];
        scanf("%s",s);
        if(s[0]=='i')
        {
            int x;
            scanf("%d",&x);
            insert(x);
        }
        else if(s[0]=='f')
        {
            int x;
            scanf("%d",&x);
            node* u=(find(root,x));
            if(u!=nil)
                printf("yes\n");
            else
                printf("no\n");
        }
        else if(s[0]=='d')
        {
            int x;
            scanf("%d",&x);
            Delete(find(root,x));
        }
        else if(s[0]=='p')
        {
            inorder(root);
            printf("\n");
            preorder(root);
            printf("\n");
        }
    }
    return 0;
}