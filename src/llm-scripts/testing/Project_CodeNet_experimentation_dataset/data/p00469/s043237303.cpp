#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

ll n,k;
ll a[20];
bool used[20];

ll ans;
map<ll,bool> mp;

void dfs(ll now, ll num){
	if(now == k){
		if(!mp[num]){
			mp[num] = true;
			ans++;
			//cout << num << "num" << endl;
		}
	}
	for (int i = 0;i < n;i++){
		if(!used[i]){
			ll nn;
			if(a[i] >= 10) nn = num * 100;
			else nn = num * 10;
			nn += a[i];
			used[i] = true;
			dfs(now+1,nn);
			used[i] = false;
		}
	}
	return;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	while(true){
		cin >> n;
		if(n == 0) break;
		cin >> k;

		for (int i = 0;i < n;i++){
			cin >> a[i];
		}

		memset(used,0,sizeof(used));
		mp = map<ll,bool>();
		ans = 0;
		
		dfs(0,0);

		cout << ans << endl;

	}

	return 0;

}

