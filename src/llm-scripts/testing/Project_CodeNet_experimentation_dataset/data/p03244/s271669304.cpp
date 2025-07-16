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
	int tmp;
	int n;
	cin >> n;
	map<int, int> o, e;
	REP(i, n){
		cin >> tmp;
		if(i %2 == 0) e[tmp] ++;
		else o[tmp]++;
	}
	vector< pair <int, int >> od , ev;
	for(auto it = e.begin(); it != e.end(); it++){
		ev.push_back(make_pair(it->second, it->first));
	}
	for(auto it = o.begin(); it != o.end(); it++){
		od.push_back(make_pair(it->second, it->first));
	}
	ev.push_back(make_pair(0, -1));
	od.push_back(make_pair(0, -1));
	sort(ev.begin(), ev.end(), greater<pair<int, int>>());
	sort(od.begin(), od.end(), greater<pair<int, int>>());
	if(ev[0].second != od[0].second){
		cout << n - ev[0].first - od[0].first;
	}
	else{
		cout << min(n - ev[1].first - od[0].first, n - ev[0].first - od[1].first);
	}
	//cout << ans << endl;
}