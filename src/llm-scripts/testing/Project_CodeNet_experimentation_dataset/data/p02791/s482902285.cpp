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
	ll n;
	cin>>n;
	ll a[n],ans=0,mins=n+1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]<mins){
			ans+=mins-a[i]-1;
			mins=a[i];
		}
	}
	cout<<n-ans;
}