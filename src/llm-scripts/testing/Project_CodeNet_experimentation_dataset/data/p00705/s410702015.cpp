#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <fstream>

using namespace std;

#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,N) for(long long i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define fi first
#define se second

#define PI acos(-1.0)
#define INF 1000000007
#define MOD 1000000007
#define EPS 1e-10
#define MAX_N 100100
#define MAX_M 100100

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, double> PD;
typedef pair<string, ll> PS;
typedef vector<ll> V;
typedef pair<P, char> PC;
typedef pair<int, string> PSI;

int n, q;
int m;


int main(){
	while (cin >> n >> q&&n + q){
		int num, ans = 0, ma = q;
		int cnt[100] = {};
		REP(i, n){
			cin >> m;
			REP(j, m){
				cin >> num;
				cnt[num]++;
			}
		}
		REP(i, 100){
			ma = max(ma, cnt[i]);
		}
		REP(i, 100){
			if (ma == cnt[i]){
				ans = i;
				break;
			}
		}
		cout << ans << endl;
	}
}