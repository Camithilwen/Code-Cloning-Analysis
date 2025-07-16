#include<bits/stdc++.h>

#define REP(i,a,b) for(int i=a;i<=b;++i)
typedef long long ll;

using namespace std;

void File(){
	freopen("AGC10D.in","r",stdin);
	freopen("AGC10D.out","w",stdout);
}

const int maxn=1e5+10;
int n;
ll a[maxn],sum;

bool dfs(bool now){
	REP(i,1,n)if(a[i]%2==1)--a[i];
	ll d=a[1];
	REP(i,1,n)d=__gcd(a[i],d);
	int cnt=0; sum=0;
	bool flag=0;
	REP(i,1,n){
		a[i]/=d;
		sum+=a[i];
		if(a[i]%2==1)++cnt;
		if(a[i]==1)flag=1;
	}
	if(sum%2==0)return now^1;
	if(sum%2==1 && (cnt>=2 || flag))return now;
	return dfs(now^1);
}

int main(){
	//File();
	scanf("%d",&n);
	REP(i,1,n){
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	if(n%2!=sum%2)puts("First");
	else if(n%2==0 && sum%2==0)puts("Second");
	else{
		int cnt=0;
		REP(i,1,n){
			if(a[i]%2==1)++cnt;
			if(cnt>=2 || a[i]==1){
				puts("Second");
				return 0;
			}
		}
		if(dfs(1))puts("First");
		else puts("Second");
	}
	return 0;
}