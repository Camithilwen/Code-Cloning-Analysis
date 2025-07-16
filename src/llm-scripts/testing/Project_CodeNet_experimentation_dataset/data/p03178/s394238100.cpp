#include<bits/stdc++.h>

#define X first
#define Y second
#define ll long long
#define MP make_pair
#define PB push_back

using namespace std;

const int MAXN=1e5;
ll MOD=1e9+7;

string s;
ll d;
ll dp[105];
ll novidp[105];
ll rj,n;
ll br;

void update(){
	for(int i=0; i<103; i++){
		dp[i]=novidp[i];
		novidp[i]=0;
	}
}

void cist(){
	memset(novidp,0,sizeof(novidp));
}

int main () {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>s>>d;
	n=s.size();
	for(int i=0; i<n-1; i++){
		br+=s[i]-'0';
	}
	for(int i='0'; i<=s[n-1]; i++){
		if((br+i-'0')%d==0){
			rj++;
		}
	}
	for(int i=0; i<=9; i++){
		dp[i%d]++;
	}
	for(int i=n-2; i>=0; i--){
		br-=s[i]-'0';
		for(int j=0; j<s[i]-'0'; j++){
			rj+=dp[(d*1000000000000-br-j)%d];
			rj%=MOD;
		}
		cist();
		for(int j=0; j<d; j++){
			for(int i=0; i<10; i++){
				novidp[(j+i)%d]+=dp[j];
				novidp[(j+i)%d]%=MOD;
			}
		}
		update();
	}
	rj--;
	if(rj==-1){
		rj=1e9+6;
	}
	cout<<rj;
	
	return 0;
}