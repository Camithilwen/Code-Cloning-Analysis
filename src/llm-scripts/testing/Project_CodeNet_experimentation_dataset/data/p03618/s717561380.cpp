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

ll cnt[26];
int main()
{
	string S; cin >> S;
	cnt[S[0] - 'a']++;
	ll ans = 1;
	for (int i = 1; i < S.size(); i++) {
		ans += i - cnt[S[i] - 'a'];
		cnt[S[i] - 'a']++;
	}
	cout << ans << endl;
}
