#include<stdio.h>
#define INF 100000
int min(int a,int b){return a<b?a:b;}
int getk(int a){
	int res=0;
	while(a>0){
		res++;
		a/=10;
	}
	return res;
}
int pow(int a,int b){
	int l;
	int rt=1;
	for(l=0;l<b;l++)rt*=10;
	return rt;
}
int card[10];
int pos[10000];
int cpos;
int main(){
	int i,j;
	int n,k;
	while(1){
	scanf("%d",&n);
	scanf("%d",&k);
	if(n==0&&k==0)return 0;
	for(i=0;i<n;i++)scanf("%d",&card[i]);
	cpos=0;
	int max=1;
	int ket;
	int next;
	int ni;
	int num;
	int ans=0;
	bool used[10];
	for(i=0;i<k;i++)max*=n;
	for(i=0;i<max;i++){
cont:		
		for(j=0;j<n;j++)used[j]=false;
		ket=1;
		ni=i;
		num=0;
		for(j=0;j<k;j++){
			next=ni%n;
			ni/=n;
			if(used[next]){
				i++;
				if(i==max)goto end;
				goto cont;
			}
			else used[next]=true;
			num+=card[next]*ket;
			ket*=pow(10,getk(card[next]));
		}
		for(j=0;j<cpos;j++){
			if(num==pos[j])break;
		}
		if(j==cpos){
			pos[cpos++]=num;
			ans++;
		}
	}
end:
	printf("%d\n",ans);
	}
}