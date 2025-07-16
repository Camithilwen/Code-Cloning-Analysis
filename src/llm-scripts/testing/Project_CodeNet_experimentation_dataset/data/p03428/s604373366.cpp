#include <bits/stdc++.h>
using namespace std;
#define _overload(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define rep(...) _overload(__VA_ARGS__, repi, _rep)(__VA_ARGS__)
double res, PI = acos(-1);
int n;
main(){
	cin >> n;
    int x[n], y[n];
	rep(i, n) cin>>x[i]>>y[i];
	rep(i, n){
        vector<double> d;
        rep(j, n) if(i != j) d.push_back(atan2(y[j] - y[i], x[j] - x[i]));
		sort(begin(d),end(d));
		res = d[0] - d[d.size() - 1] + PI;
		rep(j, 1, d.size()) res=max(res,d[j] - d[j - 1] - PI);
        cout<<max(0.0, res / 2.0 / PI)<<'\n';
	}
}