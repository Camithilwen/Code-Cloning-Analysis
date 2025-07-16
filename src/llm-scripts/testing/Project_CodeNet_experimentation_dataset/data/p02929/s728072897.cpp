#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 233;
char s[maxn];
int op[maxn]; 
int main()
{
	int n;cin>>n;
	scanf("%s",s+1);
	if(s[1]=='W'){
		puts("0");
		return 0; 
	}
	op[1] = 0;
	int cur = 1;
	ll ans = 1;
	for(int i=2;i<=2*n;i++){
		if(s[i]==s[i-1])op[i] = op[i-1]^1;
		else op[i] = op[i-1];
		if(op[i]==1){
			ans = ans*cur%mod;
			cur--;
		}
		else{
			cur++;
		}
//		cout<<"!"<<i<<" "<<cur<<endl;
		if(cur<0){
			puts("0");
			return 0;
		}
	}
//	cout<<"!"<<cur<<endl;
	if(cur){
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)ans = ans*i%mod;
	cout << ans << endl;
	return 0;
}
