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
	ll ans = 0;
	ll tmp = 0;
	ll n;
	cin >> n;
	string s = "";
	if(n==0) cout << 0 << endl;
	else {
		while(tmp != n){
			//cout << s.size() << " " << tmp << " " << s << endl;
			if(abs(n-tmp)%((ll)1<<(s.size()+1))==0) s = "0" + s;
			else {
				tmp += (ll)pow(-1, s.size()) * ((ll)1<<s.size());
				s = "1" + s;
			}
		}
		cout << s << endl;
	}
}