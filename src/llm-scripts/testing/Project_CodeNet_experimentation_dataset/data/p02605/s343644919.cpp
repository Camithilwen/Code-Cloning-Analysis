#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
ostream& operator<<(ostream &os, vector<T> &v){
	string sep = " ";
	if(v.size()) os << v[0];
	for(int i=1; i<v.size(); i++) os << sep << v[i];
	return os;
}

template<typename T>
istream& operator>>(istream &is, vector<T> &v){
	for(int i=0; i<v.size(); i++) is >> v[i];
	return is;
}

#ifdef DBG
void debug_(){ cout << endl; }
template<typename T, typename... Args>
void debug_(T&& x, Args&&... xs){
	cout << x << " "; debug_(forward<Args>(xs)...);
}
#define dbg(...) debug_(__VA_ARGS__)
#else
#define dbg(...)
#endif

int main() {
	ios_base::sync_with_stdio(false);
	cout << setprecision(20) << fixed;
	int n; cin >> n;
	vector<int> x(n), y(n);
	vector<char> u(n);
	for(int i=0; i<n; i++){
		cin >> x[i] >> y[i] >> u[i];
	}

	map<int, vector<int>> up, down, right, left;
	for(int i=0; i<n; i++){
		if(u[i]=='U') up[x[i]-y[i]].push_back(x[i]+y[i]);
		if(u[i]=='D') down[x[i]-y[i]].push_back(x[i]+y[i]);
		if(u[i]=='R') right[x[i]-y[i]].push_back(x[i]+y[i]);
		if(u[i]=='L') left[x[i]-y[i]].push_back(x[i]+y[i]);
	}

	int ans = 1e9;
	for(auto p: up){
		if(left.count(p.first)==0) continue;
		auto v = left[p.first];
		sort(v.begin(), v.end());
		for(int t: p.second){
			auto i = lower_bound(v.begin(), v.end(), t);
			if(i!=v.end()){
				ans = min(ans, 5*(*i-t));
			}
		}
	}

	for(auto p: right){
		if(down.count(p.first)==0) continue;
		auto v = down[p.first];
		sort(v.begin(), v.end());
		for(int t: p.second){
			auto i = lower_bound(v.begin(), v.end(), t);
			if(i!=v.end()){
				ans = min(ans, 5*(*i-t));
			}
		}
	}

	up.clear();
	down.clear();
	right.clear();
	left.clear();

	for(int i=0; i<n; i++){
		if(u[i]=='U') up[x[i]+y[i]].push_back(x[i]-y[i]);
		if(u[i]=='D') down[x[i]+y[i]].push_back(x[i]-y[i]);
		if(u[i]=='R') right[x[i]+y[i]].push_back(x[i]-y[i]);
		if(u[i]=='L') left[x[i]+y[i]].push_back(x[i]-y[i]);
	}

	for(auto p: right){
		if(up.count(p.first)==0) continue;
		auto v = up[p.first];
		sort(v.begin(), v.end());
		for(int t: p.second){
			auto i = lower_bound(v.begin(), v.end(), t);
			if(i!=v.end()){
				ans = min(ans, 5*(*i-t));
			}
		}
	}

	for(auto p: down){
		if(left.count(p.first)==0) continue;
		auto v = left[p.first];
		sort(v.begin(), v.end());
		for(int t: p.second){
			auto i = lower_bound(v.begin(), v.end(), t);
			if(i!=v.end()){
				ans = min(ans, 5*(*i-t));
			}
		}
	}


	up.clear();
	down.clear();
	right.clear();
	left.clear();

	for(int i=0; i<n; i++){
		if(u[i]=='U') up[x[i]].push_back(y[i]);
		if(u[i]=='D') down[x[i]].push_back(y[i]);
		if(u[i]=='R') right[y[i]].push_back(x[i]);
		if(u[i]=='L') left[y[i]].push_back(x[i]);
	}

	for(auto p: up){
		if(down.count(p.first)==0) continue;
		auto v = down[p.first];
		sort(v.begin(), v.end());
		for(int t: p.second){
			auto i = lower_bound(v.begin(), v.end(), t);
			if(i!=v.end()){
				ans = min(ans, 5*(*i-t));
			}
		}
	}

	for(auto p: right){
		if(left.count(p.first)==0) continue;
		auto v = left[p.first];
		sort(v.begin(), v.end());
		for(int t: p.second){
			auto i = lower_bound(v.begin(), v.end(), t);
			if(i!=v.end()){
				ans = min(ans, 5*(*i-t));
			}
		}
	}

	if(ans == 1e9){
		cout << "SAFE" << endl;
	} else {
		cout << ans << endl;
	}

	return 0;
}
