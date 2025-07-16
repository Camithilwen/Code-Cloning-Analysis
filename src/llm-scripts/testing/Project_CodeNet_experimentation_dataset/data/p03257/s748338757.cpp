#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
	#define DBG(n) n;
#else
	#define DBG(n) ;
#endif
#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {for(int W = 0;W < (n);W++)cerr << v[W] << ' ';cerr << endl << endl;}
#define SHOW2d(v,i,j) {for(int aaa = 0;aaa < i;aaa++){for(int bbb = 0;bbb < j;bbb++)cerr << v[aaa][bbb] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

ll mp[555][555];
int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};
vector<ll> v;

ll gcd(ll a,ll b){
	if(a < b)swap(a,b);
	return b == 0 ? a : gcd(b,a%b);
}

void prime(){
	vector<bool> pri(100000);
	vector<ll> tmp;
	int cou = 0;
	for(int i = 2;;i++){
		if(!pri[i]){
			tmp.PB(i);
			for(int j = i;j < 100000;j+=i)pri[j] = true;
			cou++;
		}
		if(cou == 1010)break;
	}
	for(int i = 0,j = tmp.size() - 1;i < j;i++,j--){
		v.PB(tmp[i]);
		v.PB(tmp[j]);
	}
}

void seica(){
	REP(i,555)REP(j,555)mp[i][j] = 1;
	REP(i,500){
		REP(j,500){
			if((i+j) % 2 == 0){
				mp[i][j] *= v[(i+j)/2];
			}
			if((i+499-j) % 2 == 1){
				mp[i][j] *= v[501+(i+499-j)/2];
			}
		}
	}

	REP(i,500){
		REP(j,500){
			if((i + j) % 2){
				ll now = 1;
				REP(k,4){
					if(i+dy[k] >= 0 && i+dy[k] < 500 && j+dx[k] >= 0 && j+dx[k] < 500){
						ll hoge = gcd(now, mp[i+dy[k]][j+dx[k]]);
						now *= mp[i+dy[k]][j+dx[k]] / hoge;
					}
				}
				mp[i][j] = now + 1;
			}
		}
	}
}

int main(){

	int n;cin >> n;

	prime();
	//cout << v.size() << endl;
	seica();

	REP(i,n){
		REP(j,n){
			cout << mp[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
