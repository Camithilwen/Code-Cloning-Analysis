#include <bits/stdc++.h>
using namespace std;

typedef long long   signed int LL;
typedef long long unsigned int LU;

#define incID(i, l, r) for(int i = (l)    ; i <  (r); i++)
#define incII(i, l, r) for(int i = (l)    ; i <= (r); i++)
#define decID(i, l, r) for(int i = (r) - 1; i >= (l); i--)
#define decII(i, l, r) for(int i = (r)    ; i >= (l); i--)
#define  inc(i, n) incID(i, 0, n)
#define inc1(i, n) incII(i, 1, n)
#define  dec(i, n) decID(i, 0, n)
#define dec1(i, n) decII(i, 1, n)

#define inII(v, l, r) ((l) <= (v) && (v) <= (r))
#define inID(v, l, r) ((l) <= (v) && (v) <  (r))

#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define PQ priority_queue

#define  ALL(v)  v.begin(),  v.end()
#define RALL(v) v.rbegin(), v.rend()
#define  FOR(it, v) for(auto it =  v.begin(); it !=  v.end(); ++it)
#define RFOR(it, v) for(auto it = v.rbegin(); it != v.rend(); ++it)

template<typename T> bool   setmin(T & a, T b) { if(b <  a) { a = b; return true; } else { return false; } }
template<typename T> bool   setmax(T & a, T b) { if(b >  a) { a = b; return true; } else { return false; } }
template<typename T> bool setmineq(T & a, T b) { if(b <= a) { a = b; return true; } else { return false; } }
template<typename T> bool setmaxeq(T & a, T b) { if(b >= a) { a = b; return true; } else { return false; } }
template<typename T> T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

// ---- ----

int n, x[100], y[100];
map<double, int> mp;
double TAU = atan2(0, -1) * 2;

void add(double l, double r) {
	if(l < 0.0) { add(1.0 + l, 1.0); add(0, r      ); return; }
	if(r > 1.0) { add(      l, 1.0); add(0, r - 1.0); return; }
	mp[l]++;
	mp[r]--;
}

int main() {
	cin >> n;
	inc(i, n) { cin >> x[i] >> y[i]; }
	
	inc(i, n) {
		mp.clear();
		mp[0.0] = 0;
		mp[1.0] = 0;
		
		inc(j, n) {
			if(i == j) { continue; }
			
			double v = atan2(y[j] - y[i], x[j] - x[i]) / TAU + 0.5;
			add(v - 0.25, v + 0.25);
		}
		
		double ans = 0.0, pre = 0.0;
		int c = 0;
		for(auto && e: mp) {
			if(c == 0) { ans += e.FI - pre; }
			c += e.SE;
			pre = e.FI;
		}
		
		printf("%.8f\n", ans);
	}
	
	return 0;
}
