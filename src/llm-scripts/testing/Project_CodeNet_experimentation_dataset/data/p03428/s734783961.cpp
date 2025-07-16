#include <bits/stdc++.h>

#define rep(i,n) for(int i=0; i<(n); i++)
#define reps(i,x,n) for(int i=x; i<(n); i++)
#define rrep(i,n) for(int i=(n)-1; i>=0; i--)
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

template<class A, size_t N, class T> void Fill(A (&a)[N], const T &v){ fill( (T*)a, (T*)(a+N), v ); }

const ll INF = 1e9+7;


int main(){
	//ios_base::sync_with_stdio(false);
	int N;
	vector<pll> v;
	map<pll, int> mp;

	cin >> N;
	rep(i,N){
		int x, y;
		cin >> x >> y;
		v.emplace_back(x, y);
		mp[pii(x,y)] = i;
	}
	sort(all(v));

	vector<int> cv[2];
	auto check = [&](int i, int k){
		pll a = v[ cv[k][cv[k].size()-2] ];
		pll b = v[ cv[k][cv[k].size()-1] ];
		pll c = v[i];
		if(k == 0) return (b.Y-a.Y) * (c.X-a.X) < (c.Y-a.Y) * (b.X-a.X);
		if(k == 1) return (b.Y-a.Y) * (c.X-a.X) > (c.Y-a.Y) * (b.X-a.X);
	};
	// rep(k,2) rep(i,N){
	// 	while( cv[k].size() >= 2 && check(i, k) ) cv[k].pop_back();
	// 	cv[k].push_back(i);
	// }
	rep(i,N){
		int k = 0;
		while( cv[k].size() >= 2 && check(i, k) ) cv[k].pop_back();
		cv[k].push_back(i);
	}
	rrep(i,N-1){
		int k = 0;
		while( cv[k].size() >= 2 && check(i, k) ) cv[k].pop_back();
		cv[k].push_back(i);
	}

	vector<int> convex;
	for(auto t: cv[0]) convex.push_back(t);
	rrep(i, cv[1].size()-1) convex.push_back(cv[1][i]);
	convex.push_back( cv[0][1] );

	//for(auto i: convex) cout << v[i].X << "," << v[i].Y << endl;

	vector<double> ans(N);
	reps(i, 1, convex.size()-1){
		pll a = v[ convex[i-1] ];
		pll b = v[ convex[i] ];
		pll c = v[ convex[i+1] ];
		double vx1 = - (b.Y - a.Y);
		double vy1 = b.X - a.X;
		double vx2 = - (c.Y - b.Y);
		double vy2 = c.X - b.X;
		double cdot = (vx1*vx2 + vy1*vy2);
		double l1 = sqrt(vx1*vx1 + vy1*vy1);
		double l2 = sqrt(vx2*vx2 + vy2*vy2);
		double ang = acos( cdot / l1 / l2 );
		int n = mp[ v[convex[i]] ];
		ans[n] = ang / 2.0 / M_PI;
	}

	for(auto t: ans) printf("%.20f\n", t);

	return 0;
}