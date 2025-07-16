#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	int arr[3];
	for(int i = 0; i < 3; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + 3);
	cout << arr[0] + arr[1];

	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}