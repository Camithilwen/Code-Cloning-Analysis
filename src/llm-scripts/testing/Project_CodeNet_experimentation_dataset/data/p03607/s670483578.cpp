#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	int n;
	scanf("%d", &n);
	int arr[n + 1];
	map<int, int> mp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (mp[arr[i]] == 0) mp[arr[i]] = 1;
		else mp[arr[i]] = 0;
	}
	long long ans = 0;
	for (auto c : mp){
		ans += c.second;
	}
	printf("%lld" , ans);
}
