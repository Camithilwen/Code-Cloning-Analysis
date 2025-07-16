#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The Value Of " << #val << " is : " << val << '\n';
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 1e5+5;
ll n, arr[nax];
unordered_map<ll, bool>vis;
unordered_map<ll, ll>cnt;
vector<ll>v;

int main(){
	IOS
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		cnt[arr[i]]++;
		if(!vis[arr[i]]){
			vis[arr[i]]=1;
			v.pb(arr[i]);
		}
	}
	sort(v.rbegin(), v.rend());
	bool udah=0;
	ll satu;
	for(auto x:v){
		if(cnt[x]>=4 && !udah){
			cout << x * x << '\n';
			return 0;
		}
		if(cnt[x]>=2){
			if(udah){
				cout << satu * x << '\n';
				return 0;
			}
			else{
				udah=1;
				satu=x;
			}
		}
	}
	cout << 0 << '\n';
}
