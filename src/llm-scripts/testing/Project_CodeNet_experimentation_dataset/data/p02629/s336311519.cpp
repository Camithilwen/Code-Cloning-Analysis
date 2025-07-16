#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){
	ll n;
	cin >> n;
	string ans = "";
	while(n != 0){
		char b = 'a' + n%26 - 1;
		if(b == '`') b = 'z';
		ans += b;
		n = (n-1)/26;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}