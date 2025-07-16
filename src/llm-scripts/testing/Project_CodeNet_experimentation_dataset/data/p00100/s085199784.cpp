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

using namespace std;

#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,N) for(long long i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define fi first
#define se second

#define PI acos(-1.0)
#define INF 1000000007
#define EPS 1e-10

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, double> PD;
typedef pair<string, ll> PS;
typedef vector<ll> V;
typedef pair<P, char> PC;


ll n;
ll index, a, b;
ll sum[5000];
V vi;

int main(){
	while (cin >> n&&n){
		vi.clear();
		fill(sum, sum + 5000, 0);
		REP(i, n){
			cin >> index >> a >> b;
			if (find(ALL(vi), index) == vi.end()){
				vi.push_back(index);
			}
			if (sum[index] >= 1000000)continue;
			sum[index] += a*b;
		}
		bool f = 1;
		REP(i, vi.size()){
			if (sum[vi[i]] >= 1000000){
				cout << vi[i] << endl;
				f = 0;
			}
		}
		if (f)cout << "NA" << endl;
	}
}