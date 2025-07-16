#define NguyenDangQuan the_author

#include <bits/stdc++.h>
#define all(x) x.begin(),x.end()
#define mset(x, i) memset(x,i,sizeof(x))
#define elif else if
#define heap priority_queue
#define fi first
#define se second
#define pb push_back
#define ld long double
#define ll long long
#define ull unsigned long long
#define task "codejam"
using namespace std;

int typetest;
template<class T>
void read(T &x){
    register int c;
    T neg = 1;
    x = (T)0;
    while ((c = getchar()) <= 47 || c >= 58)
		if(c == '-') neg = -1;
    for (; (c > 47 && c < 58); c = getchar()){
        x = (x << 3) + (x << 1) + (T)(c - 48);
    }
	x *= neg;
}
inline void fastIOfileinput(){
	ios:: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen(task".INP", "r", stdin);
//	freopen(task".OUT", "w", stdout);
//	freopen(task".in", "r", stdin);
//	freopen(task".out", "w", stdout);
	typetest = 0;
}

const int N = 2e5 + 2;
int m, n, k;
vector<int> ker[N], kel[N];
int ltr[N], ltl[N];

void Enter(){
	read(n); read(m); read(k);
	while(m--){
		int a, b;
		read(a); read(b);
		ker[a].pb(b);
		ker[b].pb(a);
	}
	while(k--){
		int a, b;
		read(a); read(b);
		kel[a].pb(b);
		kel[b].pb(a);
	}
}

void BFS(int i, int lt[], vector<int> ke[]){
	++m;
	lt[i] = m;
	queue<int> open;
	open.push(i);
	while(open.size()){
		int c = open.front();
		open.pop();
		for(auto i : ke[c]){
			if((!lt[i]))
				open.push(i), lt[i] = m;
		}
	}
}

void solve(){
	m = 0;
	for(int i = 1; i <= n; ++i)
		if(ltr[i] == 0)
			BFS(i, ltr, ker);
	m = 0;
	for(int i = 1; i <= n; ++i)
		if(ltl[i] == 0)
			BFS(i, ltl, kel);
	map<int, map<int, int> > s;
	for(int i = 1; i <= n; ++i){
		++s[ltr[i]][ltl[i]];
//		cerr << ltr[i] << " " << ltl[i] << "\n";
	}
	for(int i = 1; i <= n; ++i){
		int& v = s[ltr[i]][ltl[i]];
		cout << v << " ";
	}
}

signed main(){
	fastIOfileinput();
	if(typetest){
		int t;
		cin >> t;
		int v = t;
		while(t--){
			Enter();
			cout << "Case #" << v - t << ": ";
			solve();
		}
	}
	else{
		Enter();
		solve();
	}
}
