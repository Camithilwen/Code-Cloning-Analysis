#include<cstdio>
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<cstring>
#include<cassert>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<queue>	
#include<limits>
#include<ctime>
#include<stack>	
#include<bits/stdc++.h>
#include<string>
#include<stdlib.h>
#include<stdio.h>
	
typedef long long ll;
using namespace std;
const ll x=1000000007;
int mod(ll a){
	return a%x;
}

int main(){
	map<string,int> a;
	int n,m,maks=0;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		a[s]++;
		cout<<endl;
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>s;
		a[s]--;
		cout<<endl;
	}
	for(map<string,int>:: iterator i=a.begin();i!=a.end();i++){
		maks=max(maks,i->second);
	}	
	cout<<maks;
}
