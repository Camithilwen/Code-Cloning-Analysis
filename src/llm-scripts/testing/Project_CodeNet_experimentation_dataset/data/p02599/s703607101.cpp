//#include<bits/stdc++.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<queue>
#include<map>
#include<vector>
#include<cmath>
#include<fstream>
#include <set>
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
const int  MAXN =5e5+10;
const int mod = 1e9 + 7;
const long long INF = 0x7f7f7f7f7f7f7f7f;
const int inf= 0x3f3f3f3f;
#define eps 1e-8
#define PI 3.1415926535898
#define lowbit(x) (x&(-x))
using namespace std ;
//getline(cin,s);
//set<ll>::iterator it;
//map<int,int>::iterator it;
typedef long long ll;
int n,q;
int c[MAXN],ans[MAXN],rt,pos[MAXN],sum,a[MAXN];
struct node{
	int l,r,index;
	/*bool operator <(const node& o)const
    {
        if(pos[l]==pos[o.l]) return r<o.r;
        return pos[l]<pos[o.l];
    }*/
}need[MAXN];
int cmp(node f,node s)
{
	if(pos[f.l]==pos[s.l])
	   return f.r<s.r;
	else return f.l<s.l;
}
void add(int x)
{
	a[c[x]]++;
	if(a[c[x]]==1) sum++;
}
void del(int x)
{
	a[c[x]]--;
	if(a[c[x]]==0) sum--;
}
int main()
{
	scanf("%d %d",&n,&q);
	rt=sqrt(1.0*n);
	for(int i=1;i<=n;i++)
	{
	    scanf("%d",&c[i]);
	    pos[i]=i/rt; 
	} 
	for(int i=1;i<=q;i++)
	{
		scanf("%d %d",&need[i].l,&need[i].r);
		need[i].index=i;
	}
	sort(need+1,need+1+q,cmp);
	int l=1,r=0;
	for(int i=1;i<=q;i++)
	{
		while(l<need[i].l)
		{
			del(l);
			l++;
		}
		while(l>need[i].l)
		{
			l--;
			add(l);
		}
		while(r<need[i].r)
		{
			r++;
			add(r);
		}
		while(r>need[i].r)
		{
			del(r);
			r--;
		}
		ans[need[i].index]=sum;
	}
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
