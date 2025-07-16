#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	string s,t;
	cin >> s >>t;
	int ans = s.size() + t.size();
	int i = n;
	int j = 0;
	int leng = 1;
	int counts = 0;
	int kouho = 0;
	int kotae = s.size() + t.size();
	while(n--){
		if(s.substr(i-1,leng) == t.substr(j,leng)){
			kouho = ans - leng;
			kotae = min(kotae,kouho);
		}
		i--;
		leng++;
	}
	cout << kotae << endl;
}

// cout << fixed << setprecision(15) <<  << endl;
