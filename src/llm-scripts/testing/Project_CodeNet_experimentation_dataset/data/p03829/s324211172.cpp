#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#define IO(i, o) freopen(i, "r", stdin), freopen(o, "w", stdout)

using namespace std;
using namespace __gnu_pbds;
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());

int n, a, b, x[100000];

int main(){
	//IO("input.txt", "output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> a >> b >> x[0];
	long long cnt = 0;
	for(int i = 1; i < n; i++){
		cin >> x[i];
		cnt += min((long long)b, a * (long long)(x[i] - x[i - 1]));
	}
	cout << cnt << "\n";
	return 0;
}