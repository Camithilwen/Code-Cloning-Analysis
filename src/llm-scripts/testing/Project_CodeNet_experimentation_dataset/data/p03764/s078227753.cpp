#include <bits/stdc++.h>
using namespace std;

long long n, m, x[100004], y[100004];
const int mod = 1000000007;
long long mul(long long a, long long b){
	long long ret = a * b;
	return ret% mod;
}
long long sum(long long a, long long b){
	return (a+b)%mod;
}
int main() {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;
	for(int i = 0;i<n;i++)	cin>>x[i];
	for(int i = 0;i<m;i++)	cin>>y[i];
	int ver = 0, hor = 0;
	for(int i = 1;i<n;i++)	ver = sum(ver,mul(mul(x[i]-x[i-1],i),n-i));
	
	for(int i = 1;i<m;i++)	hor = sum(hor,mul(mul(y[i]-y[i-1],i),m-i));
	cout<<mul(ver,hor);
	return 0;
}
