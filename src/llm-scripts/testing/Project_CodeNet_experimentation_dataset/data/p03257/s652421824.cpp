#include<bits/stdc++.h>
const int N=503;
using namespace std;
typedef long long ll;
ll a[N][N];
int n,p[N*2],tot;
bool np[N*30];
inline int F(int x){
	return p[n+x/2];
}
inline int G(int x){
	return p[(x+n/2*2)/2];
}
int main(){
	scanf("%d",&n);
	for(int i=2;tot<2*n;i++){
		if(!np[i])p[tot++]=i;
		for(int j=i*i;j<N*30;j+=i)np[j]=1;
	}
	for(int i=0;i<n;i++,puts(""))
	for(int j=0;j<n;j++)
	if(i+j&1){
		printf("%lld ",1ll*F(i+j-1)*F(i+j+1)
		*G(i-j-1)*G(i-j+1)+1);
	}else printf("%d ",F(i+j)*G(i-j));
}