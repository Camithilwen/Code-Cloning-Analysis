//khodaya khodet komak kon
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#define int long long

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 600000 + 10;
const ll MOD = 1000000000 + 7;
const ll INF = 1000000010;
const ll LOG = 25;

pii adj[N];
int a[4][N], n, ind[N], rev[N], fen[N], L[N], R[N];

void add(int id, int x){
	for (id; id < N; id += (id) & (-id)) fen[id] += x;
}

int get(int id){
	int res = 0;
	for(; id > 0; id -= id & (-id)) res += fen[id];
	return res;
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= 3; j++){
			for (int k = 1; k <= 3; k++){
				if (k == j) continue;
				if (adj[(i - 1) * 3 + j].F == 0) adj[(i - 1) * 3 + j].F = (i - 1) * 3 + k;
				else adj[(i - 1) * 3 + j].S = (i - 1) * 3 + k;
			}
		} 
	}
	for (int i = 1; i <= 3; i++){
		for( int j = 1; j <= n; j++) cin >> a[i][j];
	}
//	for (int i = 1; i <= 3; i++){
//		for (int j = 1; j <= n; j++) cout << a[i][j] << ' ';
//		cout << '\n';
//	}
//	cout << a[3][4] << '\n';
	for (int j = 1; j <= n; j++){
		vi Nw;
//		if (j == 4) cout << a[1][j] << ' ' << a[2][j] << ' ' << a[3][j] << '\n';
//		cout << a[3][4] << '\n';
		for (int i = 1; i <= 3; i++) Nw.pb(a[i][j]);
		vi NN;
		NN.pb(a[1][j]);
		NN.pb(adj[a[1][j]].F);
		NN.pb(adj[a[1][j]].S);
		sort(all(Nw));
		sort(all(NN));
//		cout << a[3][4] << '\n';
//		cout << j << '\n';
//		if (j == 4) for (int j = 0; j < 3; j++) cout << Nw[j] << ' ' << NN[j] << '\n';
		for( int i = 0; i < 3; i++) if (Nw[i] != NN[i]) return cout << "No", 0;
		if (a[2][j] != ((a[1][j] - 1) / 3) * 3 + 2) return cout << "No", 0;
		if (((a[1][j] - 1) / 3 + 1) % 2 != j % 2) return cout << "No", 0;
//		cout << a[3][4] << '\n';
		ind[(a[1][j] - 1) / 3 + 1] = j;
		rev[(a[1][j] - 1) / 3 + 1] = (a[1][j] != ((a[1][j] - 1) / 3 * 3 + 1));	
	}
	int inv = 0, cnt = 0;
	for (int i = 1; i <= n; i += 2){
		inv += get(n) - get(ind[i]);
		L[i] = get(n) - get(ind[i]);
		add(ind[i], 1);
	}
	memset(fen, 0, sizeof fen);
	for (int i = n - ((n - 1) % 2); i >= 1; i -= 2){
		R[i] = get(ind[i]);
		add(ind[i], 1);
	}	
	for (int i = 1; i <= n; i += 2){
		int sm = L[i] + R[i];
		cnt += (sm + rev[i]) % 2;
	}
	memset(fen, 0, sizeof fen);
	int inv2 = 0, cnt2 = 0;
	for (int i = 2; i <= n; i += 2){
		inv2 += get(n) - get(ind[i]);
		L[i] = get(n) - get(ind[i]);
		add(ind[i], 1);
	}
	memset(fen, 0, sizeof fen);
	for (int i = n - (n % 2); i >= 2; i -= 2){
		R[i] = get(ind[i]);
		add(ind[i], 1);
	}
	for (int i = 2; i <= n; i += 2){
		int sm = L[i] + R[i];
		cnt2 += (sm + rev[i]) % 2;
	}
	if ((inv % 2 == cnt2 % 2) && (inv2 % 2 == cnt % 2)) return cout << "Yes", 0;
	cout << "No";




	return 0;
}
