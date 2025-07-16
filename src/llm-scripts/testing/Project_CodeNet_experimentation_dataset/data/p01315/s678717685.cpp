#define _CRT_SECURE_NO_WARNINGS // #pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <sstream>
#include <cmath>
#include <set>
#include <map>
#include <stack>
using namespace std; 

#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>=(b);i--)
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define all(a) a.begin(),a.end()
#define len(x) ((int)(x).size())
#define tmax(a,b,c) max((a),max((b),(c)))
#define tmin(a,b,c) min((a),min((b),(c)))
#define debug(x) cerr << #x << " is " << x << endl;
#define debug2(x,y) cerr << #x << " is " << x << " " << #y << " is " << y << endl;
#define debugg(g,h,w) rep(i,0,h) { rep(j,0,w) cout << g[i][j] << " "; cout << endl;}
#define debugv(v) for(auto&& x : v){cout << x << " ";} cout << endl;

typedef pair<int, int> Pii;
typedef map<int, int> Mii;
typedef vector<int> Vi;
typedef vector<vector<int> > VVi;
typedef long long ll;
const int inf = 2e9;
const ll ll_inf = 1e17;
const int mod = 1e9 + 7;
const long double eps = 1e-10;
typedef pair<ll, ll> Pll; 

bool opt(pair<double, string>  &lhs, pair<double, string>  &rhs) 
{
	if (lhs.first == rhs.first) return lhs.second < rhs.second;
	else return lhs.first > rhs.first;
} 

int main()
{
	int n;
	while (cin >> n && n) {
		vector<pair<double, string> > v(n);
		rep(i,0,n) {
			string l;
			int a,b,c,d,e,f,s,m,p;
			cin >> l >> p >> a >> b >> c >> d >> e >> f >> s >> m;
			double x = f*m * s - p;
			//printf("price = %lf, time = %d\n",x, (a+b+c)+m*(d+e));
			x /= (a+b+c) + m*(d+e);
			v[i] = mp(x,l);
			//printf("%s = %lf\n",l.c_str(),x);
		}
		sort(all(v), opt);
		rep(i,0,n) cout << v[i].second << endl;
		cout << "#" << endl;
	}

	return 0;
}