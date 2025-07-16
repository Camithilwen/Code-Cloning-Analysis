#include <bits/stdc++.h>
#define ll long long 
#include<vector>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int mod=1e9+7;
int main(){
	IOS;
	int n,dr;
	cin>>n>>dr;
	if(n>=10)
	cout<<dr;
	else
	cout<<dr+100*(10-n);
}