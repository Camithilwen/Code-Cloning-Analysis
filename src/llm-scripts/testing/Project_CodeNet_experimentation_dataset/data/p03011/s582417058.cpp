#include<bits/stdc++.h>
using namespace std;
const int MAX_N=1e6;
int seg_tree[2*MAX_N+5],n;
void build()
{
for(int i=n-1; i>0; --i)
seg_tree[i]=__gcd(seg_tree[i<<1],seg_tree[i<<1|1]);
}
void modify(int pos,int val)
{
for(seg_tree[pos+=n]=val; pos>1; pos>>=1)
seg_tree[pos>>1]=__gcd(seg_tree[pos],seg_tree[pos^1]);
}
int query(int l,int r)
{
int ans(1);
for(l+=n,r+=n; l<r; l>>=1,r>>=1)
{
if(l&1)
ans=__gcd(ans,seg_tree[l++]);
if(r&1)
ans=__gcd(ans,seg_tree[--r]);
}
return ans;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
int a,b,c;
cin>>a>>b>>c;
cout<<min({a,b,c})+(a+b+c-min({a,b,c})-max({a,b,c}));
}