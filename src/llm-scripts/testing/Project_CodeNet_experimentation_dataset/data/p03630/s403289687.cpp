#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007

typedef long long ll;
typedef pair<ll,ll> P;

char mp[2222][2222];
bool ng[2222][2222];
int high[2222][2222];

int seica(ll h,ll w){
	ll ret = 0;
	REP(i,h){
		stack<pair<ll,ll>> st;
		REP(j,w){
			ll tmp = j;
			while(!st.empty() && st.top().FI > high[i][j]){
				auto now = st.top();
				st.pop();
				ret = max(ret,(j - now.SE) * now.FI);
				tmp = min(tmp,now.SE);
				//cout << i << " " << j << " " << now.FI << " " << now.SE << " " << (j - now.SE) * now.FI << endl;
			}
			if(st.empty() || st.top().FI < high[i][j])st.push(MP(high[i][j],tmp));
			if(st.empty() || st.top().FI < i + 1)st.push(MP(i + 1,j));
		}
		while(!st.empty()){
			auto now = st.top();
			st.pop();
			ret = max(ret, (w - now.SE) * now.FI);
			//cout << i << " " << w << " " << now.FI << " " << now.SE << " " << (w - now.SE) * now.FI << endl;
		}
	}
	return ret;
}

int main(){
	
	int h,w;cin >> h >> w;
	REP(i,h){
		REP(j,w){
			cin >> mp[i][j];
		}
	}
	
	REP(i,h-1){
		REP(j,w-1){
			int y = i + 1;
			int x = j + 1;
			int cou = 0;
			if(mp[y][x] == '#')cou++;
			if(mp[y][x-1] == '#')cou++;
			if(mp[y-1][x] == '#')cou++;
			if(mp[y-1][x-1] == '#')cou++;
			if(cou % 2)ng[y][x] = true;
		}
	}
	
	REP(i,h){
		REP(j,w){
			if(i == 0)high[i][j] = 1;
			else {
				if(ng[i][j])high[i][j] = 1;
				else high[i][j] = high[i-1][j] + 1;
			}
		}
	}
	
	cout << seica(h,w) << endl;
	
	return 0;
}
