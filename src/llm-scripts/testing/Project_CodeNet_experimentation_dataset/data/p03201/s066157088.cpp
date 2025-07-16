#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
const int N = 2 * 1e5;
 
ll bpow(ll a, ll b) {
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a;
		a = a * a;
		b >>= 1;
	}
	return res;
}
 
int n;
map<int, int> compressed, cnt;
bitset<N> isHalf, halfCon;
set<int> halves;
 
vi conn[N];
int depth[N];
int ans = 0;


 
void count(int v, int m) {
	if (isHalf[v] && m) return;
	if (halfCon[v] && m) return;
	if (!cnt[v]) return;
	
	for (int u : conn[v]) {
		if (isHalf[u] || !cnt[u]) continue;
		if (halfCon[u] && m) return;
		int lim = min(cnt[u], cnt[v]);
		cnt[u] -= lim, cnt[v] -= lim;
		ans += lim;
	}
	
	if (isHalf[v]) {
		ans += cnt[v] / 2;
		cnt[v] %= 2;
	}
}


struct Comp
{
    // Compare 2 Player objects using name
    bool operator ()(const int& a, const int& b)
    {
		if (halfCon[a]) return false;
		if (halfCon[b]) return true;
        return depth[a] <= depth[b];
    }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	vi a(n);
	rep(i, 0, n) {
		cin >> a[i];
		compressed[a[i]];
	}
	
	int pos = 0;
	for (auto& x : compressed) {
		if (!(bpow(2, ceil(log2(x.first))) - x.first)) {
			isHalf[pos] = 1;
			halves.insert(pos);
		}
		x.second = pos++;
	}
	
	rep(i, 0, n) {
		a[i] = compressed[a[i]];
		++cnt[a[i]];
	}
	
	for (pii i : compressed) {
		ll nxt = bpow(2, ceil(log2(i.first))) - i.first;
		if (nxt != i.first && compressed.count(nxt)) {
			conn[i.second].push_back(compressed[nxt]);
			conn[compressed[nxt]].push_back(i.second);
		}
	}
	
	queue<int> q, rq;
	vector<bool> vis(pos, false);
	
	rep(i, 0, pos) {
		if (sz(conn[i]) == 1) {
			q.push(i);
			vis[i] = true;
		}
	}
	
	while (!q.empty()) {
		int v = q.front();
		rq.push(v);
		q.pop();
		for (auto u : conn[v]) {
			if (!vis[u]) {
				q.push(u);
				depth[u] = depth[v] + 1;
				vis[u] = true;
			}
		}
	}
	
	halfCon.reset();
	set<int> semiHalves;
	for (int i : halves) {
		for (int u : conn[i]) {
			halfCon[u] = true;
			semiHalves.insert(u);
		}
	}
	
	rep(i, 0, n) {
		sort(all(conn[i]), Comp());
	}
	
	while (!rq.empty()) {
		int v = rq.front();
		rq.pop();
		count(v, 1);
	}
	
	for (int i : semiHalves) {
		count(i, 0);
	}
	
	for (int i : halves) {
		count(i, 0);
	}
	cout << ans;
}
