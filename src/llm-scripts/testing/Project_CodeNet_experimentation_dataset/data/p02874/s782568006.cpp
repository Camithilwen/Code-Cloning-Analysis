#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <queue>
#include <set>
#include <bitset>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>




#define ll long long
#define uint unsigned int
#define ull unsigned ll
#define mp make_pair
#define pb push_back
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define speedhack() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define do(x) for(int i = 1; i <= x; i++){ solve(); }
#define sz(x) (int)x.size()
#define pii pair < int, int >
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
const ll MAXN = 1e18;
const ll SIZE = 5e5 + 10;  //are u sure?
const ll mod = 1e9+7;
ll Lpref[SIZE], Rpref[SIZE];
ll Lsuff[SIZE], Rsuff[SIZE];
ll L[SIZE], R[SIZE];
ll mR = MAXN, mL = -MAXN;


void solve(){
	int N; cin >> N;
	for(int i = 0; i < N; i++){
		cin >> L[i] >> R[i];
		mR = min(mR, R[i]);
		mL = max(mL, L[i]);
	}
	Lpref[0] = -MAXN;
	Rpref[0] = MAXN;
	for(int i = 0; i < N; i++){
		Lpref[i + 1] = max(Lpref[i], L[i]);
		Rpref[i + 1] = min(Rpref[i], R[i]);
	}

	Lsuff[N - 1] = L[N - 1];
	Rsuff[N - 1] = R[N - 1];
	for(int i = N - 1; i > 0; i--){
		Lsuff[i - 1] = max(Lsuff[i], L[i]);
		Rsuff[i - 1] = min(Rsuff[i], R[i]);
	}
	ll ans = 0;
	for(int i = 0; i < N; i++){
		ll cur = (R[i] - L[i] + 1) + max(0LL, min(Rpref[i], Rsuff[i + 1]) - max(Lpref[i], Lsuff[i + 1]) + 1);
		ans = max(ans, cur);
	}
	vector<pair<ll, ll>> vec;
	for(int i = 0; i < N; i++){
		vec.push_back(mp(L[i], R[i]));
	}
	sort(all(vec));
	for(int i = N - 1; i > 0; i--){
		vec[i - 1].second = min(vec[i - 1].second, vec[i].second);
	}
	for(int i = 0; i + 1 < N; i++){
		ll cur = max(0LL, mR - vec[i].first + 1) + max(0LL, vec[i + 1].second - mL + 1);
		ans = max(ans, cur);
	}
	cout << ans << endl;
}

int main(){
	speedhack()
	// int it; cin >> it;
	int it = 1;
	do(it);
	return 0;
}