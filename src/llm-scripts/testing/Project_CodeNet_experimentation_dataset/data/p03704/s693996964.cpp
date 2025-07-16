#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
#include<cassert>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=500000004;
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
long long p10[20];
long long calc(int a,int b,int c,long long d){
	if(b>c){
		if(d==0)return 1;
		else return 0;
	}
	if(b==c){
		if(d==0)return 10;
		else return 0;
	}
	if(ABS(d)>=p10[c+1])return 0;
	long long ret=0;
	for(int i=-10;i<10;i++){
		int ks=10-ABS(i);
		if(b==0&&i>=0)ks--;
		ret+=calc(a,b+1,c-1,d-i*(p10[c]-p10[b]))*ks;
	}
	return ret;
}
int main(){
	p10[0]=1;
	for(int i=1;i<20;i++)p10[i]=p10[i-1]*10;
	int a;scanf("%d",&a);
	long long ret=0;
	for(int i=2;i<=18;i++){
		ret+=calc(i,0,i-1,a);
	//	printf("%d\n",ret);
	}
	printf("%lld\n",ret);
}