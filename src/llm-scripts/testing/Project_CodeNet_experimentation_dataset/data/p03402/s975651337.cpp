#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	int a,b;cin>>a>>b;
	vector<vector<char>> v(100,vector<char>(100,'#'));
	for(int i = 50; i < 100; i++) {
		for(int j = 0; j < 100; j++) {
			v[i][j] = '.';
		}
	}
	int h = 0,w = 0;
	a--;b--;
	while(a > 0){
		v[h][w] = '.';
		if (w + 2 < 100){
			w += 2;
		}
		else{
			w = 0;
			h += 2;
		}
		a--;
	}
	h = 51,w = 0;
	while(b > 0){
		v[h][w] = '#';
		if (w + 2 < 100){
			w += 2;
		}
		else{
			w = 0;
			h += 2;
		}
		b--;
	}
	cout << 100 << " " << 100 << endl;
	for(int i = 0; i < 100; i++) {
		for(int j = 0; j < 100; j++) {
			cout << v[i][j];
		}
		cout << endl;
	}



	return 0;
}