#include <bits/stdc++.h>

using namespace std;
#define SIZE 262144
#define int long long
#define INF 1000000000000000000LL
class segtree{
public:
	int seg[SIZE * 2];
	void update(int a, int b){
		a += SIZE;
		seg[a] = b;
		while(true){
			a /= 2;
			if (a == 0)break;
			seg[a] = min(seg[a * 2], seg[a * 2 + 1]);
		}
	}
	int query(int beg, int end, int node, int lb, int ub){
		if (ub < beg || end < lb)return INF;
		if (beg <= lb&&ub <= end)return seg[node];
		return min(query(beg, end, node * 2, lb, (lb + ub) / 2), query(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub));
	}
};
int dp[SIZE];
segtree tree1, tree2;
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n, q, a, b;
	cin >> n >> q >> a >> b;
	a--, b--;
	int curb = b;
	fill(dp, dp + n, INF);
	dp[a] = 0;
	for (int i = 0; i < n; i++){
		tree1.update(i, dp[i] + i);
	}
	for (int i = 0; i < n; i++){
		tree2.update(i, dp[i] - i);
	}
	int dif = 0;
	for (int p = 0; p < q; p++){
		int z;
		cin >> z;
		z--;
		int t1 = tree2.query(0, z, 1, 0, SIZE - 1) + dif + z;
		int t2 = tree1.query(z, n - 1, 1, 0, SIZE - 1) + dif - z;
		dif += abs(z - curb);
		if (dp[curb] + dif > min(t1, t2)){
			dp[curb] = min(t1, t2) - dif;
			tree1.update(curb, dp[curb] + curb);
			tree2.update(curb, dp[curb] - curb);
		}
		curb = z;
	}
	int mn = INF;
	for (int i = 0; i < n; i++){
		mn = min(mn, dp[i] + dif);
	}
	cout << mn;
}