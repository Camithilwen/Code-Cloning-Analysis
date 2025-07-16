
// Problem : C - Low Elements
// Contest : AtCoder - AtCoder Beginner Contest 152
// URL : https://atcoder.jp/contests/abc152/tasks/abc152_c
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include<bits/stdc++.h>
#include<set>
#define lli long long int
#define pb push_back
#define cio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define rep(i,a,n) for(i=a;i<n;i++)
#define all(v) (v.begin(),v.end())
#define ppb pop_back
#define vsz v.size()
#define pi 3.141592653589793238
using namespace std;
int main()
{
	lli t,n,i,k=1e6;
	cin>>n;
	vector<lli>v;
	for(i=0;i<n;i++){
		cin>>t;
		v.pb(t);
	}
	t=0;
	for(i=0;i<n;i++){
		if(v[i]<k)
		t++;
		k=min(k,v[i]);
	}
	cout<<t;
	return 0;
}