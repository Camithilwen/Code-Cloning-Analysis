#include<cstdio>
int H,W,A[2010][2010],h[2010],l[2010],stk[2010];
char S[2010][2010];
void cmax(int&a,int b){b>a?a=b:1;}
int main(){
	scanf("%d%d",&H,&W);
	for(int i=0;i<H;i++){
		scanf("%s",S[i]);
		for(int j=0;j<W;j++){
			S[i][j]=S[i][j]=='#';
			if(i&&j)A[i][j]=S[i][j]^S[i][j-1]^S[i-1][j]^S[i-1][j-1]^1;
		}
	}
	int ans=H>W?H:W;
	for(int i=1;i<H;i++){
		int*tp=stk;
		for(int j=1;j<=W;j++){
			h[j]=A[i][j]?h[j]+1:0;
			for(;tp>stk&&h[*tp]>=h[j];--tp)
				cmax(ans,(j-l[*tp])*(h[*tp]+1));
			l[j]=*tp;
			*++tp=j;
		}
	}
	printf("%d\n",ans);
}