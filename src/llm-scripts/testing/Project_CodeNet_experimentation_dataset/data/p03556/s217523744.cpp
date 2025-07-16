#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 1e9 + 10;
const ll INFLL = 3e18;

int main(){
	
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	
	int ans = 1;
	int n;
	cin >> n;
	
	for(int i = 1 ; i*i <= n ; i ++)
		ans = i*i;
	
	cout << ans << "\n";
	
	return 0;
}