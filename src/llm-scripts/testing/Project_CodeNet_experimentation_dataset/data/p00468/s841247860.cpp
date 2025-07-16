#include<stdio.h>
#include<algorithm>
using namespace std;
int main(void)
{
    int n,m,a[10000],b[10000],flg[10001],i,h;
	while(1){
	    scanf("%d %d",&n,&m);
		if(n==0&&m==0) break;
		for(i=2;i<=n;i++) flg[i]=0;
		for(i=0;i<m;i++){
		    scanf("%d %d",&a[i],&b[i]);
		}
		for(i=0;i<m;i++){
		    if(a[i]==1){
			    flg[b[i]]=1;
			}
		}
		h=0;
		for(i=0;i<m;i++){
		    if(flg[a[i]]==1){
			    if(flg[b[i]]==0){
				    flg[b[i]]=2;
				}
			}
			if(flg[b[i]]==1){
			    if(flg[a[i]]==0){
				    flg[a[i]]=2;
				}
			}
		}
		for(i=2;i<=n;i++){
		    if(flg[i]>0){
			    h++;
			}
		}
		printf("%d\n",h);
	}
	return 0;
}