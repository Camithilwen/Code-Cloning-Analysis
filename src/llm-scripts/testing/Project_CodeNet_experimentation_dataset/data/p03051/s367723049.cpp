#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#define int long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define F first
#define S second
using namespace std;
typedef pair<int,int>pii;
const int maxn=500010;
const int N=1<<20;
const int mod=1e9+7;
int n;
int a[maxn],f[maxn];
int flg[maxn];//1-i中异或和不为0的个数
int d1[N];//
int d0[N];//
int pre[N];//上一个异或和为i的数
signed main(){
	cin>>n;
	for(int i=0;i<(1<<20);i++)d0[i]=1;
	for(int i=0;i<n;i++)cin>>a[i],f[i]=(i>0?(f[i-1]^a[i]):a[i]);
	for(int i=0;i<n;i++){
		if(f[i]){
			int b=f[i];//当前的异或和
			d0[b]=(d0[b]+(flg[i]-flg[pre[b]])*d1[b])%mod;
			d1[b]=(d0[b]+d1[b])%mod;
			pre[b]=i;
		}else{
			flg[i]++;
			if(d1[0])d1[0]=(d1[0]*2)%mod;
			else d1[0]++;
		}
		flg[i+1]=flg[i];
	}
	int ans=0;
	if(f[n-1]==0){
		for(int i=0;i<(1<<20);i++)ans=(ans+d1[i])%mod;
	}else{
		ans=d0[f[n-1]];
	}
	cout<<ans<<endl;
	return 0;
}
