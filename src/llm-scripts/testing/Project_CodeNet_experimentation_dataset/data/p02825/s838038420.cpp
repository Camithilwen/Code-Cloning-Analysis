#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 998244353

typedef long long ll;
typedef pair<ll,ll> P;

char mp[1111][1111];
char san[3][3] = {
{'a','.','.'},
{'a','.','.'},
{'.','b','b'}};

char san2[3][3] = {
{'z','w','w'},
{'z','.','x'},
{'y','y','x'}};

char four[4][4] = {
{'a','a','c','d'},
{'b','b','c','d'},
{'c','d','a','a'},
{'c','d','b','b'}};

char five[5][5] = {
{'a','h','h','g','g'},
{'a','i','.','.','f'},
{'b','i','.','.','f'},
{'b','.','j','j','e'},
{'c','c','d','d','e'}};
char seven[7][7] = {
{'a','b','c','.','.','.','.'},
{'a','b','c','.','.','.','.'},
{'.','.','.','d','e','f','f'},
{'.','.','.','d','e','g','g'},
{'k','k','l','.','.','c','c'},
{'m','.','l','a','a','.','.'},
{'m','n','n','b','b','.','.'}};

void yon(int a, int b){
	REP(i, 4){
		REP(j, 4){
			mp[i+a][j+b] = four[i][j];
		}
	}
}

void roku(int a, int b){
	REP(i, 6){
		REP(j, 6){
			if(((i / 3) + (j / 3)) % 2)mp[i+a][j+b] = san[i%3][j%3];
			else mp[i+a][j+b] = san2[i%3][j%3];
		}
	}
}

void kyuu(int a, int b){
	REP(i, 9){
		REP(j, 9){
			mp[i+a][j+b] = san[i%3][j%3];
		}
	}
}

void go(int a, int b){
	REP(i, 5){
		REP(j, 5){
			mp[i+a][j+b] = five[i][j];
		}
	}
}

void seica(int n, int cou){
	for(int i = 0;;i++){
		int j = (n - cou) - i * 6;
		if(j < 0)continue;
		if(j % 9 == 0){
			j /= 9;
			REP(ii, i){
				roku(cou, cou);
				cou +=6;
			}
			REP(jj, j){
				kyuu(cou, cou);
				cou +=9;
			}
			return;
		}
	}
}

int main(){
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(false);

	REP(i, 1111)REP(j, 1111)mp[i][j] = '.';

	ll n;cin >> n;
	if(n % 3 == 0){
		REP(i, n){
			REP(j, n){
				cout << san[i%3][j%3];
			}
			cout << endl;
		}
	}
	else if(n % 5 == 0){
		REP(i, n){
			REP(j, n){
				cout << five[i%5][j%5];
			}
			cout << endl;
		}
	}
	else if(n % 7 == 0){
		REP(i, n){
			REP(j, n){
				cout << seven[i%7][j%7];
			}
			cout << endl;
		}
	}
	else if(n % 4 == 0){
		REP(i, n){
			REP(j, n){
				cout << four[i%4][j%4];
			}
			cout << endl;
		}
	}
	else if(n > 5 && n % 3 == 2) {
		int cou = 0;
		go(cou, cou);
		cou += 5;
		seica(n, cou);
		REP(i, n){
			REP(j, n){
				cout << mp[i][j];
			}
			cout << endl;
		}
	}
	else if(n > 8 && n % 3 == 1){
		int cou = 0;
		yon(cou, cou);
		cou += 4;
		seica(n, cou);
		REP(i, n){
			REP(j, n){
				cout << mp[i][j];
			}
			cout << endl;
		}
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}
