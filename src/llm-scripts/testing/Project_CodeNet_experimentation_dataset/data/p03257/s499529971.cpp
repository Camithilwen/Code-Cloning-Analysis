#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-10;
const double INF=1e+10;
const double PI=acos(-1.0);
const int C_SIZE = 3121000;
long long fact[C_SIZE];
long long finv[C_SIZE];
long long inv[C_SIZE];
long long Comb(int a,int b){
 	if(a<b||b<0)return 0;
 	return fact[a]*finv[b]%mod*finv[a-b]%mod;
}
void init_C(int n){
	fact[0]=finv[0]=inv[1]=1;
	for(int i=2;i<n;i++){
		inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
	}
	for(int i=1;i<n;i++){
		fact[i]=fact[i-1]*i%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
}
long long pw(long long a,long long b){
	long long ret=1;
	while(b){
		if(b%2)ret=ret*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ret;
}
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
// ここから編集しろ
long long ans[510][510];
int p[21000];
vector<int>v;
long long gcd(long long a,long long b){
	while(a){b%=a;swap(a,b);}return b;
}
int main(){
	int a;scanf("%d",&a);
	if(a==2){
		printf("4 7\n23 10\n");return 0;
	}
	p[0]=p[1]=-1;
	for(int i=2;i<21000;i++){
		if(p[i]!=-1){
			if(i>2)v.push_back(i);
			p[i]=1;
			for(int j=i+i;j<21000;j+=i)p[j]=-1;
		}
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			if((i+j)%2)continue;
			int X=(i+j)/2;
			int Y=(i-j+500)/2+500;
			long long ks=1;
			ks*=v[X];
			ks*=v[Y];
			ans[i][j]=ks;
		}
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			if((i+j)%2){
				long long cur=1;
				if(i)cur=cur/gcd(cur,ans[i-1][j])*ans[i-1][j];
				if(j)cur=cur/gcd(cur,ans[i][j-1])*ans[i][j-1];
				if(i<a-1)cur=cur/gcd(cur,ans[i+1][j])*ans[i+1][j];
				if(j<a-1)cur=cur/gcd(cur,ans[i][j+1])*ans[i][j+1];

				cur++;
				ans[i][j]=cur;
			}
		}
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			if(j)printf(" ");
			printf("%lld",ans[i][j]);
		}
		printf("\n");
	}
}