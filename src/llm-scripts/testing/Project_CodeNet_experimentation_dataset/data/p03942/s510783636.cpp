#include<bits/stdc++.h>
using namespace std;
int n,lst[1000100][26],gg[1000100];
char s[1000100],t[1000100];

struct treaps
{
	int son[1201000][2],size[1201000],num[1201000],tag[1201000],rd[1200100],tt;
	void update(int s){size[s]=size[son[s][0]]+size[son[s][1]]+1;}
	int build(int n)
	{
		if (n==0) return 0;
		int s=++tt;size[s]=1;
		n--;
		son[s][0]=build(n/2);son[s][1]=build(n-n/2);
		update(s);
		return s;
	}
	inline void pushdown(int s)
	{
		if (son[s][0]) {tag[son[s][0]]+=tag[s];num[son[s][0]]+=tag[s];}
		if (son[s][1]) {tag[son[s][1]]+=tag[s];num[son[s][1]]+=tag[s];}
		tag[s]=0;
	}

	void addtag(int s) {tag[s]++;num[s]++;}
	int merge(int s,int t)
	{
		if (!s) return t;
		if (!t) return s;
		pushdown(s);pushdown(t);
		if ((rand()*32768+rand())%(size[s]+size[t])<size[s]) {son[s][1]=merge(son[s][1],t);update(s);return s;}
		else {son[t][0]=merge(s,son[t][0]);update(t);return t;}
	}
	pair<int,int> split(int s,int k)
	{
		if (!s) return pair<int,int>(0,0);
		pushdown(s);
		if (size[son[s][0]]>=k)
		{
			pair<int,int> ls=split(son[s][0],k);
			son[s][0]=ls.second;update(s);
			return pair<int,int>(ls.first,s);
		}
		pair<int,int> ls=split(son[s][1],k-size[son[s][0]]-1);
		son[s][1]=ls.first;update(s);
		return pair<int,int>(s,ls.second);
	}
	int findkth(int s,int k)
	{
		while (1)
		{
			pushdown(s);
			if (size[son[s][0]]>=k) s=son[s][0];
			else if (size[son[s][0]]+1==k) return num[s];
			else {k-=(size[son[s][0]]+1);s=son[s][1];}
		}
	}
}treap;
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d\n%s\n%s",&n,s+1,t+1);
	bool err=false;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<26;j++) lst[i][j]=lst[i-1][j];
		lst[i][s[i]-'a']=i;
		if (s[i]!=t[i]) err=true;
	}
	if (err==false) {printf("0\n");return 0;}
	int root=treap.build(n),ans=1,rem=n;
	for (int i=n;i>=1;i--) if (t[i]!=t[i-1])
	{//if (i%10000==0) cerr<<i<<' '<<treap.size[root]<<endl;
		//for (int j=1;j<=i;j++) cout<<treap.findkth(root,j)<<' ';cout<<endl;
		int w=treap.findkth(root,i);
		if ((w!=0)||(s[i]!=t[i])) ans=max(ans,w+2);
		int d=lst[min(i-(w!=0),rem)][t[i]-'a'];rem=d-1;
			if (d==0) {printf("-1\n");return 0;}
			pair<int,int> p=treap.split(root,d-1);
			pair<int,int> q=treap.split(p.second,1);
			treap.addtag(q.second);
			root=treap.merge(p.first,q.second);
		
	}
	printf("%d\n",ans);
}