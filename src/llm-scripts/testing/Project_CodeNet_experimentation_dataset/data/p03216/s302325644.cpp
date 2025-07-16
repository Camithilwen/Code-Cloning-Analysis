#include <bits/stdc++.h>
#define rep(i,n) for(int i=(0);i<(n);i++)

using namespace std;

typedef long long ll;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	string s;
	cin >> s;

	int q;
	cin >> q;

	vector<int> v(q);
	rep(i, q) cin >> v[i];

	vector<int> dsum(n+1, 0);
	rep(i, n) dsum[i+1] += dsum[i] + (s[i] == 'D' ? 1 : 0);

	for(int k : v){
		ll ans = 0;
		deque<int> q;

		ll t = 0;
		for(int i = 0; i < n; i++){
			if(i-k >= 0 && s[i-k] == 'D'){
				t -= q.size();
			}
			
			if(q.size() > 0 && q.back() < i - (k - 2)){
				q.pop_back();
			}

			if(s[i] == 'M'){
				q.push_front(i);
				t += dsum[i] - dsum[max(i-(k-1), 0)];
			}

			if(s[i] == 'C') ans += t;
		}

		cout << ans << endl;
	}
}
