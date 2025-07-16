#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repe(i,n) for(int i=0;i<n;i++)
#define repa(i,j,n) for(int i=j;i<n;i++)
//#define v.all() v.begin(),v.end()
#define repr(i,n) for(int i=n;i>=0;i--)
#define int long long int
#define vi vector<int>
#define vpi vector<pair<int,int>>
int gcd(int a,int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}
vi primef(int n){
	vi a,ref;
	a.push_back(1);
	while(n%2==0) {
		a.push_back(2);
		n/=2;
	}
	for(int i=3;i<=sqrt(n);i+=2){
		while(n%i==0){
			a.push_back(i);

			n/=i;
		}
	}
	if(n>2) a.push_back(n);
	sort(a.begin(), a.end());
	ref.push_back(a[0]);
	for(int i=1;i<a.size();i++){
		if(a[i]!=a[i-1]) {
			ref.push_back(a[i]);
		}
	}
	return ref;
}

signed  main(){
	int t=1;
	//cin>>t;
	while(t--) {
		int ai,bi;
		cin>>ai>>bi;
		vi a,b;
		a=primef(ai);
		b=primef(bi);
		// for(int i=0;i<a.size();i++){
		// 	cout<<a[i]<<" ";
		// }
		// cout<<endl;
		// for(int i=0;i<b.size();i++){
		// 	cout<<b[i]<<" ";
		// }
		// cout<<endl;
		int ct=0;
		map<int,int> m;
		rep(i,a.size()) m[a[i]]=0;
		rep(i,b.size()) m[b[i]]=0;
		rep(i,a.size()) m[a[i]]=1;
		rep(i,b.size()){
			if(m[b[i]]==1) {ct++;}
		}
		cout<<ct<<endl;
	}
	return 0;
}