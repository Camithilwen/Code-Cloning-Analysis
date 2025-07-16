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
const double PI = 3.14159265358979323846264338327950288;

ll A[100010];
ll sum[100010];
int main()
{
	int N;
	ll M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> A[i];
	ll ans = 0;
	map<ll, ll> mp;
	for (int i = 0; i < N; i++) {
		sum[i + 1] = (sum[i] + A[i]) % M;
	}
	sort(sum, sum + N + 1);
	ll cnt = 1;
	for (int i = 0; i < N; i++) {
		if (sum[i] == sum[i + 1]) {
			cnt++;
		}
		else {			
			ans += cnt * (cnt - 1) / 2;
			cnt = 1;
		}
	}
	ans += cnt * (cnt - 1) / 2;
	cout << ans << endl;
}
