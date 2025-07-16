#include <bits/stdc++.h>

using namespace std;


const int N = 100100;
#define ll long long
#define fr(i,a,n) for (int i=a;i<n;i++)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vipb(v) int x;cin>>x;v.pb(x);
#define vllpb(v) ll x;cin>>x;v.pb(x);
#define in(x) cin>>x;
#define in2(x,y) cin >> x >> y;
#define in3(x,y,z) cin>>x>>y>>z;
#define in4(a,x,y,z) cin>>a>>x>>y>>z;
#define in5(a,b,x,y,z) cin>>a>>b>>x>>y>>z;


typedef vector<int> VI;
typedef vector<ll> VL;


string s;
ll n, m, k;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		if (i + k -1<= n)
			m++;
	}
	cout << m << endl;
	return 0;
}