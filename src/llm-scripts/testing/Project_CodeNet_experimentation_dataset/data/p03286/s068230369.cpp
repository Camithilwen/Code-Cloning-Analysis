#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mt make_tuple
#define all(x) (x).begin(), (x).end() 
#define MOD 1000000007

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef long double ld;

const ll INF=LLONG_MAX;
ll pow2[32];
vector<char>s(32,'0');
vll dp,dp2;

void init(){
	pow2[0]=1LL;
	for(int i=1; i<32; i++)
		pow2[i] = pow2[i-1]*2LL;
	for(int i=0; i<32; i+=2){
		if(dp.empty())dp.eb(pow2[i]);
		else dp.eb(pow2[i]+dp.back());
	}
	for(int i=1; i<32; i+=2){
		if(dp2.empty())dp2.eb(pow2[i]);
		else dp2.eb(pow2[i]+dp2.back());
	}
}

void solve(int x){
	if(x==0)return;
	else if(x<0){
		auto ptr = lower_bound(all(dp2),x*-1)-dp2.begin();
		int next = x+pow2[ptr*2+1];
		s[ptr*2+1]='1';
		solve(next);
	}else{
		auto ptr = lower_bound(all(dp),x)-dp.begin();
		int next = x-pow2[ptr*2];
		s[ptr*2]='1';
		solve(next);
	}
	return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int x; cin >> x;
	init();
	if(x==0){
		cout << 0 << endl;
		return 0;
	}
	solve(x);
	reverse(all(s));
	bool st=0;
	for(auto ch:s){
		if(ch=='1')st=1;
		if(st)cout << ch;
	}
}
	
// READ & UNDERSTAND
// ll, int overflow, array bounds, memset(0)
// special cases (n=1?), n+1 (1-index)
// do smth instead of nothing & stay organized
// WRITE STUFF DOWN
