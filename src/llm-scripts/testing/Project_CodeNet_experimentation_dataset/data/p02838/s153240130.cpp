#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD=1000000007;

LL nol[60],satu[60];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int n;
	LL a;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a;
		for(int j=0;j<60;j++){
			if(a & (1LL<<j))satu[j]++;
			else nol[j]++;
		}
	}
	LL ans=0;
	for(int i=0;i<60;i++){
		LL byk=(nol[i]*satu[i])%MOD,res=((1LL<<i))%MOD;
		ans=(ans+((byk*res)%MOD))%MOD;
	}
	cout << ans << '\n';
	return 0;
}

