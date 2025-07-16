#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

int A[100010];
int cnt[100010];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	ll ans = 1;
	for (int i = 0; i < N; i++) {
		if (A[i] == 0) {
			ans *= 3 - cnt[A[0]];
		}
		else {
			ans *= cnt[A[i] - 1] - cnt[A[i]];
		}
		cnt[A[i]]++;
		ans %= mod;
	}
	cout << ans << endl;
}
