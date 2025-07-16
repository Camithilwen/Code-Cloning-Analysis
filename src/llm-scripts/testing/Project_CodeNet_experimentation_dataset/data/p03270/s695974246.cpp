#include <bits/stdc++.h>
typedef long long ll;

const int N=5005,P=998244353;
int n,k,C[N][N];

inline int Cs(int n,int m){return n<0||m<0||n<m?0:C[n][m];}

int main()
{
	scanf("%d%d",&k,&n);
	for(int i=C[0][0]=1;i<=5001;++i)
		for(int j=C[i][0]=1;j<=i;++j)
			if((C[i][j]=C[i-1][j]+C[i-1][j-1])>=P)
				C[i][j]-=P;
	for(int i=2,j,u,v,s;i<=k<<1;printf("%d\n",s),++i)
		for(u=std::min(k,i>>1),v=std::max(1,i-k),s=j=0;j<=u-v+1;++j)
			s=(s+(ll)Cs(u-v+1,j)*Cs(n+k-j-j-1,n-j-j)%P*(j&1?P-1:1))%P;
	return 0;
}
