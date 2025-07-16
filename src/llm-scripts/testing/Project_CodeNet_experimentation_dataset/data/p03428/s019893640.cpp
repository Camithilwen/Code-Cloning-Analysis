#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)

int n,x[101],y[101];
const double PI=acos(-1);
double k[101];

int main(){
	scanf("%d",&n);
	if(n==2){puts("0.5\n0.5");return 0;}
	F(i,1,n) scanf("%d%d",x+i,y+i);
	F(i,1,n){
		int cnt=0;
		F(j,1,n) if(j!=i){
			k[++cnt]=atan2(x[j]-x[i],y[j]-y[i]);
		}
		std::sort(k+1,k+cnt+1);
		double t;
		t=k[1]-k[cnt]+PI+PI;
		if(t>=PI) {printf("%.15lf\n",(t-PI)/(PI+PI)); continue;}
		bool ok=0;
		F(j,1,cnt-1){
			t=k[j+1]-k[j];
			if(t>=PI) {printf("%.15lf\n",(t-PI)/(PI+PI)); ok=1; break;}
		} if(!ok) printf("%.15lf\n",0.);
	}
	return 0;
}