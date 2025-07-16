#include <bits/stdc++.h>


using namespace std;

#define ll long long

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	vector<int> a(N);
	bool ok=true;
	int ans=1e9;
	//O(N * LOG(MAX(a)))
	for(int& x : a) {
		cin >> x;
		if(x&1) ok=false;
		int cnt=0;
		while(x) {
			if(x&1) {
				ans=min(ans,cnt);
				break;
			}
			cnt++;
			x/=2;
		}
	}
	if(!ok) {
		puts("0");return 0;
	}else {
		cout << ans;
	}
	return 0;
}
