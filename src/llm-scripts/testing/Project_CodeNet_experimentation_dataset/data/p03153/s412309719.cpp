#include<bits/stdc++.h>
using namespace std;
#define maxn 240000
typedef long long LL;
const LL mod = 1000000007;
LL A[maxn], D;
LL mi[2][maxn * 4];
void build(int p, int o, int l, int r){
	if(l == r){
		mi[p][o] = p ? D * l + A[l] : - D * l + A[l];
		return;
	}
	int m = (l + r) >> 1;
	build(p, o * 2, l, m);
	build(p, o * 2 + 1, m + 1, r);
	mi[p][o] = min(mi[p][o * 2], mi[p][o * 2 + 1]);
}
LL ask(int p, int o, int l, int r, int L, int R){
	if(l >= L && r <= R) return mi[p][o];
	int m = (l + r) >> 1;
	LL ret = 1E18;
	if(L <= m) ret = min(ret, ask(p, o * 2, l, m, L, R));
	if(R > m) ret = min(ret, ask(p, o * 2 + 1, m + 1, r, L, R));
	return ret;
}
void update(int p, int o, int l, int r, int i){
	if(l == r) mi[p][o] = 1E18;
	else{
		int m = (l + r) >> 1;
		if(i <= m) update(p, o * 2, l, m, i);
		else update(p, o * 2 + 1, m + 1, r, i);
		mi[p][o] = min(mi[p][o * 2], mi[p][o * 2 + 1]);
	}
}
vector<pair<LL, int> > v;
int main(){
	int N;
	cin >> N >> D;
	LL ans = D * (N - 1);
	for(int i = 1; i <= N; i += 1){
		cin >> A[i];
		ans += A[i] << 1;
	}
	ans -= A[1] + A[N];
	for(int i = 2; i < N; i += 1) v.push_back(make_pair(A[i], i));
	sort(v.begin(), v.end());
	build(0, 1, 1, N);
	build(1, 1, 1, N);
	for(auto p : v){
		int i = p.second;
		LL L = ask(0, 1, 1, N, 1, i - 1) + D * i - A[i];
		LL R = ask(1, 1, 1, N, i + 1, N) - D * i - A[i];
		if(L >= 0 && R >= 0) continue;
		ans += min(L, R);
		update(0, 1, 1, N, i);
		update(1, 1, 1, N, i);
	}
	cout << ans;
}