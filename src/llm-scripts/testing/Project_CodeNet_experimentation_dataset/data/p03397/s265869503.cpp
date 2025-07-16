#include<cstdio>
#include<cstring>
#define mod 1000000007
#define ran 333333
char s[ran];int n;
int a[ran],p2[ran];
int dp[3],dp2[3];
int add(int x,int y){
	return (x+=y)<mod?x:x-mod;
}
void addto(int&x,int y){
	x =add(x,y);
}
int mul(int x,int y){
	return (int)((long long int)x*y%mod);
}
const int trans[3][4]={
{0,1,0,1},
{0,1,2,3},
{2,2,2,3}
};
int main(){
	scanf("%s",s);
	n = strlen(s);
	if(n == 1){
		printf("%d\n",s[0]=='0'?0:1);
		return 0;
	}
	p2[0] = 1;for(int i=1; i<=n; i++)p2[i] = add(p2[i-1],p2[i-1]);
	for(int i=n-1; i>=0; i--)a[i] = a[i+1] + (s[i] == '?');

	int res = 0;
	for(int i=0; i<n-1; i+=2){
		dp2[0] = dp2[1] = dp2[2] = 0;
		for(int c1=0; c1<2; c1++)if(s[i] == '?' || s[i] == c1 + '0')
			for(int c2=0; c2<2; c2++)if(s[i+1] == '?' || s[i+1] == c2 + '0'){
				int T = c1 * 2 + c2;
				if(i==0){
					if(T == 3)addto(res, p2[a[i+2]]);else
						addto(dp2[T], 1);
				}else{
					for(int k=0; k<3; k++)
						if(trans[k][T] == 3)
							addto(res, mul(dp[k],p2[a[i+2]]));
						else
							addto(dp2[trans[k][T]], dp[k]);
				}
		}
		dp[0] = dp2[0];
		dp[1] = dp2[1];
		dp[2] = dp2[2];
	}
	if(s[n-1] == '?' || s[n-1] == '1'){
		addto(res,dp[1]);
		addto(res,dp[2]);
	}
	printf("%d\n",res);
	return 0;
}