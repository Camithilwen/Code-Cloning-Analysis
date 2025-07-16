//JOI 2008??´???3??? ?????????

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;

#define MAX -210000000
#define MIN 210000000

int a,b;
int d[1002],c[1001*1001],hk=0,mcunt,low,high;
int x,pr=0/*,flg[200000000]*/,m,ff=0;

int main(){ 
	
	scanf("%d %d",&a,&b);
	while(a!=0 && b!=0){
		d[0]=0;
		hk=0;
		ff=0;
		pr=0;
		for(int i=1;i<=a;i++) scanf("%d",&d[i]);
		
		for(int i=0;i<=a;i++){
			for(int j=0;j<=a;j++){
				c[hk]=d[i]+d[j];
				hk++;
			}
		}
		sort(c,c+hk);									 
		for(int i=0;i<hk;i++){
			x=b-c[i];
			low=0;
			high=hk-1;
			while(low<=high){
				m=(low+high)/2;
				if(x==c[m]){
					ff=1;
					break;
				}
				if(x>c[m]) low=m+1;
				else if(x<c[m]) high=m-1;
			}
			if(ff==1){
				pr=c[i]+c[m];
				break;
			}
			if(b>c[i]+c[high] && pr<c[i]+c[high]){
				pr=c[i]+c[high];
			}
		}
		printf("%d\n",pr);
		scanf("%d %d",&a,&b);
	}
	return 0;
}