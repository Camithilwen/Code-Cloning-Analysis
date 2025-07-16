#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

template<class T> T gcd(const T& a,const T& b){ return b==0?a:gcd(b,a%b); }

int main(){
	int n,k; scanf("%d%d",&n,&k);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);

	int g=a[0];
	rep(i,n-1) g=gcd(g,a[i+1]);

	puts(k%g==0&&k<=*max_element(a.begin(),a.end())?"POSSIBLE":"IMPOSSIBLE");

	return 0;
}
