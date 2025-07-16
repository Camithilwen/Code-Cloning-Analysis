//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF INT_MAX
#define LLINF LLONG_MAX
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
    for (T& x: vec) { is >> x; }
    return is;
}

int main() {
	ll ans = 0;
	ll tmp;
	//int n; cin >> n;
	vector<string> s(3);
	cin >> s[0] >> s[1] >> s[2];
	int who = 0;
	while(1){
		if(s[who].size()==0){
			cout << (char)('A' + who) << endl;
			break;
		}
		else{
			int next = s[who][0] - 'a';
			s[who] = s[who].substr(1);
			who = next;
		}
	}
	//cout << ans << endl;
}