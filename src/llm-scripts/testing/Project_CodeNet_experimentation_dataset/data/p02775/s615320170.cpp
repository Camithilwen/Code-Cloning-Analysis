#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	string t;
	cin>>t;
	reverse(t.begin(),t.end());
	t+='0';
	ll ch[1000010][2];
	for(ll i=0;i<1000010;i++){
		for(ll j=0;j<2;j++){
			ch[i][j]=INF;
		}
	}
	ch[0][0]=0;
	for(ll i=0;i<t.size();i++){
		ll now=t[i]-'0';
		for(ll a=0;a<=9;a++){
			ll num=now;
			if(a>=now){
				ch[i+1][0]=min(ch[i+1][0],ch[i][0]+2*a-num);
			}
			if(a<now){
				ch[i+1][1]=min(ch[i+1][1],ch[i][0]+a+10-num);
			}
			if(a>=now+1){
				ch[i+1][0]=min(ch[i+1][0],ch[i][1]+2*a-(num+1));
			}
			if(a<now+1){
				ch[i+1][1]=min(ch[i+1][1],ch[i][1]+2*a+10-(num+1));
			}
		}
	}
	cout << ch[t.size()][0];
	// your code goes here
	return 0;
}
