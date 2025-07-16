#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int p=1e9+7;
char s[300010];
int n,i,j,ans,k,f[300010][3][3];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	f[0][0][0]=1;
	for(i=1;i<=n;i++){
		if(s[i]!='1'){
			for(j=0;j<3;j++)
			 for(k=0;k<3;k++){
			 	if(k==2){
			 		f[i][j][k-1]=(f[i][j][k-1]+f[i-1][j][k])%p;
				 }
				  else f[i][j][k+1]=(f[i][j][k+1]+f[i-1][j][k])%p;
			 }
		}
		if(s[i]!='0'){
			for(j=0;j<3;j++)
			 for(k=0;k<3;k++){
			 	if(k==0)(f[i][j+(j!=2)][k]+=f[i-1][j][k])%=p;
			 	 else (f[i][j][k-1]+=f[i-1][j][k])%=p;
			 }
		}
	}
	for(i=0;i<3;i++)
	 for(j=0;j<=i;j++)ans=(ans+f[n][i][j])%p;
	printf("%d",ans);
}