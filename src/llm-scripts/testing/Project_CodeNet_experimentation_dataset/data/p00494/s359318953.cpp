#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <numeric>
#include <iomanip>

using namespace std;

#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,N) for(long long i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define fi first
#define se second

#define PI acos(-1.0)
#define INF 1000000007
#define EPS 1e-10
#define MAX_N 20000
#define MAX_M 16

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, double> PD;
typedef pair<string, ll> PS;
typedef vector<ll> V;
typedef pair<P, char> PC;

string s;
vector<P> p;//fi:pos  se:co

int main(){
	cin >> s;
	int ans = 0;
	int pos = 0;
	int co = 0;
	REP(i, s.size()){
		if (s[i] == 'O'){
			if (co == 0)pos = i;
			co++;
		}
		else if (co > 0){
			if (s[i] != 'O'){
				p.push_back(P(pos, co));
				co = 0;
			}
		}
	}
	if (co > 0)p.push_back(P(pos, co));
	REP(i, p.size()){
		int po = p[i].first;
		int w = p[i].second;
		//cout << po << " " << w << endl;
		bool f = 1;
		if (po - w >= 0){
			string t = s.substr(po - w, w);
			//cout << t << endl;
			REP(j, t.size()){
				if (t[j] != 'J')f = 0;
			}
		}
		else f = 0;
		if (po + w + w - 1 <= s.size() - 1){
			string t = s.substr(po + w, w);
			//cout << t << endl;
			REP(j, t.size()){
				if (t[j] != 'I')f = 0;
			}
		}
		else f = 0;
		if (f)ans = max(ans, w);
	}
	cout << ans << endl;
}