#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
using namespace std;
int d[30],len,dp[30][30][30];
int DP(int n){
	int ret=0;
	memset(dp,0,sizeof(dp));
	dp[0][0][0]=1;
	for(int i=0;i<(n>>1);i++)
		for(int j=0;j<10;j++)
			for(int k=0;k<10;k++)
				if(dp[i][j][k])
					for(int x=0;x<10;x++){
						int l1=x+d[i+1]+k,y=l1%10,l2=10*j+x-y-d[n-i];
						l1/=10;
 						if(l2<0||l2>9||(!i&&(!x||!y)))
							continue;
						dp[i+1][l2][l1]+=dp[i][j][k];
					}
	if(n&1){
		int mid=(n+1)>>1;
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				if(dp[n>>1][i][j])
					for(int x=0;x<10;x++){
						int y=x+d[mid]+j;
						if(x==y%10&&y/10==i)
							ret+=dp[n>>1][i][j];
					}
	}
	else
		for(int i=0;i<10;i++)
			ret+=dp[n>>1][i][i];
	return ret;
}
int getans(){
	int ret=0;
	for(int i=max(2,len);i<=20;i++)
		ret+=DP(i);
	return ret;
}
void Input(){
	char c;
	do c=getchar();
	while(!isdigit(c));
	do{
		d[++len]=c^48;
		c=getchar();
	}while(isdigit(c));
	reverse(d+1,d+len+1);
	return;
}
int main(){
	Input();
	printf("%d",getans());
	return 0;
}