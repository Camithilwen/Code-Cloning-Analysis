#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	rep(i,(1<<3)){
		int num = (s[0] - '0');
		rep(j,3){
			if(i>>j & 1){
				num += (s[j+1] - '0');
			}
			else{
				num -= (s[j+1] - '0');
			}
		}
		if(num == 7){
			cout << s[0] << ((i>>0 & 1) ? "+" : "-");
			cout << s[1] << ((i>>1 & 1) ? "+" : "-");
			cout << s[2] << ((i>>2 & 1) ? "+" : "-");
			cout << s[3] << "=7" << endl;
			return 0;
		}
	}
	return 0;
}