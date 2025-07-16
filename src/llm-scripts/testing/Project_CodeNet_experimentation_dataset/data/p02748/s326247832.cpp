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

int main(){
	ll a,b,m;
	cin>>a>>b>>m;
	ll x[a],y[b],mins1=100005,mins2=100005;
	for(int i=0;i<a;i++){
		cin>>x[i];
		mins1=min(mins1,x[i]);
	}
	for(int i=0;i<b;i++){
		cin>>y[i];
		mins2=min(mins2,y[i]);
	}
	ll mins=mins1+mins2;
	for(int i=0;i<m;i++){
		ll d,e,f,now;
		cin>>d>>e>>f;
		now=x[d-1]+y[e-1]-f;
		mins=min(now,mins);
	}
	cout<<mins;
}

