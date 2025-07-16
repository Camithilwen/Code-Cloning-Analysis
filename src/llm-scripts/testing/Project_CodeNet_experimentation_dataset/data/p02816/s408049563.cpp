#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
    print(v[i],i==(int)(v.size())-1?suc:2);
}
const int maxn=4e5+7;
int a[maxn],b[maxn];
int s[maxn],t[maxn];
int len;
int fail[maxn];
void getfail()
{
    memset(fail, 0, sizeof(fail));
    int j = 0, k = fail[0] = -1;
    while (j < len)
    {
        while (k != -1 && t[j] != t[k])
            k = fail[k];
        fail[++j] = ++k;
    }
}
vi ans;
int kmp()
{
    int n = len*2, m = len;
    int i = 0, j = 0;
    int ret = 0;
    while (i < n)
    {
        while (j != -1 && s[i] != t[j])
            j = fail[j];
        i++, j++;
        if (j == m)
        {
            ans.push_back(i-len);
            ret++, j = fail[j];
        }
    }
    return ret;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int j=0;j<n;j++) cin>>b[j];
    if(n==1)
    {
        cout<<0<<" "<<(a[0]^b[0])<<'\n';
        return 0;
    }
    for(int i=1;i<n+n;i++) s[i-1]=a[i%n]^a[(i-1)%n];
    for(int i=1;i<n;i++) t[i-1]=b[i]^b[i-1];
    len=n-1;
    getfail();
    kmp();
    for(auto u:ans) cout<<u<<" "<<(b[0]^a[u])<<'\n';
}