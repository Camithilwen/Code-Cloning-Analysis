#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(long long i=0;i<x;i++)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<pair<string,P> >vec;

#define MAX_N 200001

long long par2[MAX_N]; // 親
long long rankuf2[MAX_N]; // 木の深さ
// n要素で初期化
void init2(long long n) {
	for (long long i = 0; i < n; i++) {
		par2[i] = i;
    rankuf2[i] = 0;
	}
}
// 木の根を求める
long long find2(long long x) {
	if (par2[x] == x) {
		return x;
	} else {
		return par2[x] = find2(par2[x]);
	}
}
// xとyの属する集合を併合
void unite2(long long x, long long y) {
	x = find2(x);
	y = find2(y);
	if (x == y) return;
	if (rankuf2[x] < rankuf2[y]) {
		par2[x] = y;
	} else {
		par2[y] = x;
		if (rankuf2[x] == rankuf2[y]) rankuf2[x]++;
	}
}
// xとyが同じ集合に属するか否か
bool same2(long long x, long long y) {
	return find2(x) == find2(y);
}

long long par[MAX_N]; // 親
long long rankuf[MAX_N]; // 木の深さ
// n要素で初期化
void init(long long n) {
	for (long long i = 0; i < n; i++) {
		par[i] = i;
    rankuf[i] = 0;
	}
}
// 木の根を求める
long long find(long long x) {
	if (par[x] == x) {
		return x;
	} else {
		return par[x] = find(par[x]);
	}
}
// xとyの属する集合を併合
void unite(long long x, long long y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (rankuf[x] < rankuf[y]) {
		par[x] = y;
	} else {
		par[y] = x;
		if (rankuf[x] == rankuf[y]) rankuf[x]++;
	}
}
// xとyが同じ集合に属するか否か
bool same(long long x, long long y) {
	return find(x) == find(y);
}

int main(){	
	long long K;
	long long N;
	long long L;
	scanf("%lld",&N);
	scanf("%lld",&K);
	init(N+1);
	init2(N+1);
	vector<long long> q(K-1+1);
	vector<long long> p(K-1+1);
	scanf("%lld",&L);
	vector<long long> r(L-1+1);
	vector<long long> s(L-1+1);
	for(int i = 0 ; i <= K-1 ; i++){
		scanf("%lld",&p[i]);
		scanf("%lld",&q[i]);
		unite(p[i]-1, q[i]-1);
	}
	for(int i = 0 ; i <= L-1 ; i++){
		scanf("%lld",&r[i]);
		scanf("%lld",&s[i]);
		unite2(r[i]-1, s[i]-1);
	}
	map<P, ll> m;
	rep(i, N) {
		m[P(find(i), find2(i))]++;
	}
	ll cnt = 0;
	rep(i, N-1) {
		cout << m[P(find(i), find2(i))] << " ";
	}
	cout << m[P(find(N-1), find2(N-1))] << endl;
	return 0;
}

