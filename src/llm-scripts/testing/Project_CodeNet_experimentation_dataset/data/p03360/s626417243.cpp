#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int a,b,c,k;
	cin >> a >> b >> c >> k;
	int mn = max(a,max(b,c));
	int ans = a + b + c - mn + pow(2,k) * mn;
	cout << ans << endl;
}