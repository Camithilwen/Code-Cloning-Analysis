#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200010;
int a[N], n;
ll sum[N];
ll get(int l, int r){
	return sum[r] - sum[l - 1];
}
inline void chkmin(ll& a, ll b){
	if(a > b) a = b;
}
inline void chkmax(ll& a, ll b){
	if(a < b) a = b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	ll ans = 1LL << 60;
	for(int i = 3; i <= n - 1; i++){
		ll a[4];
		int low = i, high = n - 1;
		int step = 100;
		int mid1, mid2;
		while(step-- && low <= high){
			mid1 = (low + low + high) / 3;
			mid2 = (low + high + high) / 3;
			ll s1 = get(i, mid1), s2 = get(mid1 + 1, n);
			ll s3 = get(i, mid2), s4 = get(mid2 + 1, n);
			if(abs(s1 - s2) > abs(s3 - s4))
				low = mid1 + 1;
			else
				high = mid2;
		}
		vector<pair<ll, ll> > vp1;
		for(int j = -2; j <= 2; j++){
			int nh = high + j;
			if(nh >= i && nh + 1 <= n)
				vp1.emplace_back(get(i, nh), get(nh + 1, n));
		}
		
		low = 2, high = i - 1;
		step = 100;
		while(step-- && low <= high){
			mid1 = (low + low + high) / 3;
			mid2 = (low + high + high) / 3;
			ll s1 = get(mid1, i - 1), s2 = get(1, mid1 - 1);
			ll s3 = get(mid2, i - 1), s4 = get(1, mid2 - 1);
			if(abs(s1 - s2) > abs(s3 - s4))
				low = mid1 + 1;
			else
				high = mid2;
		}
		
		a[2] = get(high, i - 1), a[3] = get(1, high - 1);
		
		vector<pair<ll, ll> > vp2;
		for(int j = -2; j <= 2; j++){
			int nh = high + j;
			if(nh <= i - 1 && 1 <= nh - 1)
				vp2.emplace_back(get(nh, i - 1), get(1, nh - 1));
		}
		for(auto it : vp1) for(auto jt : vp2){
			ll a[4] = {it.first, it.second, jt.first, jt.second};
			ll xv = 0, nv = 1LL << 60;
			for(int j = 0; j < 4; j++)
				chkmax(xv, a[j]), chkmin(nv, a[j]);
			chkmin(ans, xv - nv);
		}
	}
	cout << ans << "\n";
	return 0;
}
