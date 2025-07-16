//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	int ans = 0;
	int tmp;
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = "-" + s;
	bool sw[n+2] = {}, las, fir, ch = false;
	REP(i, 2){
		if(ch) break;
		REP(j, 2){
			if(ch) break;
			sw[1] = i;
			sw[n] = j;
			sw[0] = j;
			las = j;
			fir = i;
			for(int k = 1; k <= n; k++){
				if(s[k] == 'o') sw[k+1] = sw[k-1];
				else sw[k+1] = !sw[k-1];
				if(!sw[k]) sw[k+1] = !sw[k+1];
				//cout << k << " " << sw[k-1] << " " << sw[k] << " " << sw[k+1] << endl;
			}
			if(fir == sw[n+1] && las == sw[n]) ch = true;
		}
	}
	if(ch){
		REP1(i, n){
			if(sw[i]) cout << "S";
			else cout << "W";
		}
		cout << endl;
	}
	else cout << -1 << endl;
}