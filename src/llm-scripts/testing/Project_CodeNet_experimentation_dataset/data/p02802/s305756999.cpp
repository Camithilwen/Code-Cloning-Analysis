#include<bits/stdc++.h>							
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;
const ll maxsize = 100000009;



vector<bool> mark(100005, 0);
int wa[100005];
void solve() {
	int n, k;
	cin >> n >> k;
	map<string,ll> m;
	m["AC"] = 0;
	int ac_cnt = 0, wa_cnt = 0;
	m["WA"] = 0;
	int t = 0;
	for(int i = 0; i < k; ++i) {
		int x;
		string s;
		cin >> x >> s;	
		if(mark[x]) continue;
		if(s == "AC") {
			mark[x] = 1;
			ac_cnt++;
			wa_cnt += wa[x];
			}
			else wa[x]++;
		}
		cout << ac_cnt <<" "<< wa_cnt << endl;
		cout << endl;
}


int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
}
 
 
 

