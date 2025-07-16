#include<cmath>  
#include<queue>  
#include<vector>  
#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
#define INF 1000005 
#define MAXN 500000
int read() 
{ 
    int f=1,x=0;char s=getchar(); 
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();} 
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();} 
    return x*f; 
} 
struct node{
	int key;
	node *ch[2],*fa;
};
node tree[MAXN+5];
node *Root,*NIL,*ncnt;
void Init()
{
	NIL=&tree[0];
	NIL->fa=NIL->ch[0]=NIL->ch[1]=NIL;
	ncnt=&tree[1];
	Root=NIL;
	return ;
}
inline node *NewNode(int val)
{//插入新的?点
	node *p=++ncnt;
	p->key=val;
	p->fa=p->ch[0]=p->ch[1]=NIL;
	return p;
}
void Insert(node *&rt,node *fa,int val)
{//插入(?造二叉排序?)
	if(rt==NIL)
	{
		rt=NewNode(val);
		rt->fa=fa;
		return ;
	}
	int d=(val>=rt->key);
	Insert(rt->ch[d],rt,val);
	return ;
}
void InOrder(node *rt)
{//?出
	if(rt==NIL) return ;
	InOrder(rt->ch[0]);
	printf(" %d",rt->key);
	InOrder(rt->ch[1]);
	return ;
}
void PreOrder(node *rt)
{//?出
	if(rt==NIL) return ;
	printf(" %d",rt->key);
	PreOrder(rt->ch[0]);
	PreOrder(rt->ch[1]);
	return ;
}
node *Find(node *rt,int val)
{//找一?在??中
	if(rt==NIL) return NIL;
	if(rt->key==val) return rt;
	int d=(val>=rt->key);
	return Find(rt->ch[d],val);
}
node *FindNext(node *rt)
{
	if(rt==NIL) return NIL;
	node *y=rt->ch[1];
	while(y->ch[0]!=NIL)
		y=y->ch[0];
	return y;
}
void Delete(node *rt,int val)
{
	node *x,*y,*z=Find(rt,val);
	if(z==NIL) return ;
	if(z->ch[0]==NIL||z->ch[1]==NIL)
		y=z;
	else
		y=FindNext(z);
	if(y->ch[0]!=NIL)
		x=y->ch[0];
	else
		x=y->ch[1];
	if(x!=NIL)
		x->fa=y->fa;
	if(y->fa==NIL)
		Root=x;
	else
	{
		int d=(y==y->fa->ch[1]);	
		y->fa->ch[d]=x;
	}
	if(y!=z)
		z->key=y->key;
	return ;
}
int main()
{
    int n=read(),x;
	char op[20];
	Init();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",op);
		if(op[0]=='i')
		{
			x=read();
			Insert(Root,NIL,x);
		}
		else if(op[0]=='f')
		{
			x=read();
			if(Find(Root,x)==NIL)
				printf("no\n");	
			else
				printf("yes\n");
		}
		else if(op[0]=='d')
		{
			x=read();
			Delete(Root,x);
		}
		else
		{
			InOrder(Root);
			puts("");
			PreOrder(Root);
			puts("");
		}
	}
	return 0;  
}  