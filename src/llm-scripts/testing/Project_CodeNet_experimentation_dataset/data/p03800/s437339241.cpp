#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
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
const int INF=0x3f3f3f3f;
const int maxn=1e5+7;
int n;
string s;
int main()
{
	cin>>n;
	cin>>s;
	bool ok=0;
	string op;
	for(int st=0;st<2;st++)
	{
		for(int ed=0;ed<2;ed++)
		{
			op=(st?"S":"W");
			for(int i=0;i<s.length()-1;i++)
			{
				char pre=(i?op[i-1]:(ed?'S':'W'));
				char cur=op[i];
				if(s[i]=='o')
				{
					if(cur=='S')
						op+=pre;
					else op+=(pre=='W'?'S':'W');
				}
				else{
					if(cur=='W')
						op+=pre;
					else op+=(pre=='W'?'S':'W');
				}
				//dbg(st,ed,i);
	//			dbg(op);
			}
			char edd=(ed?'S':'W');
			if(edd==op[s.length()-1])
			{
				if(s[s.length()-1]=='o')
				{
					char pre=op[s.length()-2];
					if((pre==op[0]&&edd=='S')||(pre!=op[0]&&edd=='W'))
					{
						ok=1;
						break;
					}
				}
				else{
					char pre=op[s.length()-2];
					if((pre==op[0]&&edd=='W')||(pre!=op[0]&&edd=='S'))
					{
						ok=1;break;
					}
				}
			}
		}
		if(ok) break;
	}
	if(!ok) cout<<"-1\n";
	else cout<<op<<'\n';
}
