#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

int main(){
	int n; cin >> n;
	string s; cin >> s;
	int open=0, ans=1;
	for(int i=0;i<2*n;i++){
		if((s[i]=='B' && (open&1)) || (s[i]=='W' && (!(open&1)))){
			if(open<=0){
				cout << 0 << endl;
				return 0;
			}
			ans=(1ll*ans*open)%mod;
			open--;
		}
		else{
			open++;
		}
	}
	for(int i=1;i<=n;i++){
		ans=(1ll*ans*i)%mod;
	}
	if(open==0){
		cout << ans << endl;
	}
	else{
		cout << 0 << endl;
	}
	return 0;
}