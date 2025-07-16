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
#define INF 10e9+9
#define EPS 1e-10
#define MAX_N 100100
#define MAX_M 100100

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, double> PD;
typedef pair<string, ll> PS;
typedef vector<ll> V;
typedef pair<P, char> PC;

int n, k[1000];
string s;

int main(){
	while (cin >> n&&n){
		REP(i, n)cin >> k[i];
		cin >> s;
		int key = 0;
		REP(i, s.size()){
			REP(j, k[key]){
				if (s[i] == 'a'){
					s[i] = 'Z';
				}
				else if (s[i] == 'A'){
					s[i] = 'z';
				}
				else{
					s[i]--;
				}
			}
			key++;
			if (key >= n)key = 0;
		}
		cout << s << endl;
	}
}