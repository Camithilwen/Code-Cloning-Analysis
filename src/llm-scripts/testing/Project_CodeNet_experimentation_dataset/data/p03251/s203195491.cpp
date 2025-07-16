#include <bits/stdc++.h>
#define INF 2e9
#define MOD 1000000007
#define MOD9 998244353
#define intMAX 51000;
#define PI 3.14159265359
using namespace std;
typedef long long llong;
typedef long double ldouble;

using Graph = vector<vector<int>>;

int main(){
	int N, M, X, Y;
	cin >> N >> M >> X >> Y;
	int maxx = -101;
	int miny = 101;
	for(int i=0; i<N; ++i){
		int x;
		cin >> x;
		maxx = max(maxx, x);
	}
	for(int i=0; i<M; ++i){
		int y;
		cin >> y;
		miny = min(miny, y);
	}
	maxx = max(maxx, X);
	miny = min(miny, Y);
	if(maxx<miny) cout << "No War" << endl;
	else cout << "War" << endl;
}