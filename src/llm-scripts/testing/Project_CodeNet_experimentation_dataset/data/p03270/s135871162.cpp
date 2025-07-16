#include<stdio.h>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Mod=998244353;
int k,n,ans[4100],C[4100][4100];
int calc(int x,int k,int n){
	int tmp,sum=0;
	for (int i=0;i<=(x-1)/2&&n-i*2>=0;i++){
		if (!k) tmp=0;
		else tmp=(ll)C[(x-1)/2][i]*C[n-i*2+k-1][k-1]%Mod;
		if (i&1) sum=(sum-tmp+Mod)%Mod;
		else sum=(sum+tmp)%Mod;
	}
	return sum;
}
int main(){
	C[0][0]=1;
	for (int i=1;i<=4000;i++){
		C[i][0]=1;
		for (int j=1;j<=i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%Mod;
	}
	scanf("%d%d",&k,&n);
	for (int i=2;i<=k+1;i++)
		if (!(i&1)) ans[i]=(calc(i,k-1,n)+calc(i,k-1,n-1))%Mod;
		else ans[i]=calc(i,k,n);
	for (int i=2;i<=k;i++) printf("%d\n",ans[i]);
	printf("%d\n",ans[k+1]);
	for (int i=k;i>=2;i--) printf("%d\n",ans[i]);
	return 0;
}
