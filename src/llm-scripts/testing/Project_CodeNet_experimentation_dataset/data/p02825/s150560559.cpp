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

void rec(vector<vector<int>> &b, int k, vector<vector<vector<int>>> &res){
	int n = b.size();
	int mx = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) mx=max(mx, b[i][j]);
	}
	int si=0, sj=0;
	if(mx>0){
		bool done = false;
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				if(b[i][j]==mx){
					si = i;
					sj = j;
					done=true;
					break;
				}
			}
			if(done) break;
		}
	}

	int x = -1;
	bool ok = true;
	for(int i=0; i<n; i++){
		set<int> a;
		for(int j=0; j<n; j++){
			if(b[i][j]>0) a.insert(b[i][j]);
		}
		if(x<0) x = a.size();
		if(a.size()>k) return;
		if(x!=a.size()){
			if(i<si) return;
			ok = false;
		}
	}
	for(int i=0; i<n; i++){
		set<int> a;
		for(int j=0; j<n; j++){
			if(b[j][i]>0) a.insert(b[j][i]);
		}
		if(a.size()>k) return;
		if(x!=a.size()) ok = false;
	}
	if(ok && x==k){
		res.push_back(b);
		return;
	}

	for(int i=si; i<n; i++){
		for(int j=(i==si?sj:0); j<n; j++){
			if(i+1<n&&b[i][j]==0&&b[i+1][j]==0){
				b[i][j] = b[i+1][j] = mx+1;
				rec(b, k, res);
				if(res.size()) return;
				b[i][j] = b[i+1][j] = 0;
			}
			if(j+1<n&&b[i][j]==0&&b[i][j+1]==0){
				b[i][j] = b[i][j+1] = mx+1;
				rec(b, k, res);
				if(res.size()) return;
				b[i][j] = b[i][j+1] = 0;
			}
		}
	}
}

vector<vector<vector<int>>> naive(int n, int k){
	vector<vector<vector<int>>> ret;
	vector<vector<int>> b(n, vector<int>(n));
	rec(b, k, ret);
	return ret;
}

string x3[3] = {
	"aab",
	"c.b",
	"cdd",
};

string x4[4] = {
	"aabc",
	"ddbc",
	"efgg",
	"efhh",
};

string x5[5] = {
	"..abc",
	"..abc",
	"ddeef",
	"ggh.f",
	"iihjj",
};

string x6[6] = {
	"abc...",
	"abc...",
	"d.eeff",
	"dghh..",
	".g.ijj",
	"kk.ill",
};

string x7[7] = {
	"abc....",
	"abc....",
	"def....",
	"def....",
	"g..hhii",
	"g..jjkk",
	".llmmnn",
};


int main() {
	ios_base::sync_with_stdio(false);
	cout << setprecision(20) << fixed;

	int n; cin >> n;

	if(n<=2){
		cout << -1 << endl;
		return 0;
	}

	if(n==3){
		for(int i=0; i<3; i++) cout << x3[i] << endl;
		return 0;
	}

	int k = n%4+4;
	int l = n/4-1;
	for(int i=0; i<l; i++){
		for(int j=0; j<4; j++){
			cout << string(i*4, '.') << x4[j] << string(n-4*(i+1), '.') << endl;
		}
	}
	if(k==4){
		for(int j=0; j<4; j++){
			cout << string(n-4, '.') << x4[j] << endl;
		}
	} else if(k==5){
		for(int j=0; j<5; j++){
			cout << string(n-5, '.') << x5[j] << endl;
		}
	} else if(k==6){
		for(int j=0; j<6; j++){
			cout << string(n-6, '.') << x6[j] << endl;
		}
	} else if(k==7){
		for(int j=0; j<7; j++){
			cout << string(n-7, '.') << x7[j] << endl;
		}
	}

	return 0;
}
