#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N, K;
	cin >> N >> K;
	int ans = 0;
	for(int i = 1; i <= N - K + 1; ++i) {
		ans++;
	}
	cout << ans << endl;
}








