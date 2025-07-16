#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>
#define M 2100000
using namespace std;	
int main(void)
{
	int i,j,n,k,m,a[3001],b[3001],cost[3001],time[3001],kk,pp,bre;
	int p,q,r;
	int kin[101][101],zi[101][101];
	int flg[10001],leng[10001],min;
	int kaku,skin,szi;
	
	while(1) {
		scanf("%d %d",&n,&m);
		if(n==0 && m==0) break;
		for(i=1;i<=n;i++) scanf("%d %d %d %d",&a[i],&b[i],&cost[i],&time[i]);
		//??£??\????????????  ??????
		for(i=1;i<=m;i++) {
			for(j=1;j<=m;j++) {
				kin[i][j]=M;
			}
		}
		for(i=1;i<=m;i++) kin[i][i]=0;
		for(i=1;i<=n;i++)	kin[a[i]][b[i]]=cost[i];
		for(i=1;i<=n;i++)	kin[b[i]][a[i]]=cost[i];
		//??£??\???????????????
		for(i=1;i<=m;i++) {
			for(j=1;j<=m;j++) {
				zi[i][j]=M;
			}
		}
		for(i=1;i<=m;i++) zi[i][i]=0;
		for(i=1;i<=n;i++) zi[a[i]][b[i]]=time[i];
		for(i=1;i<=n;i++) zi[b[i]][a[i]]=time[i];
		scanf("%d",&k);
		for(i=1;i<=k;i++) {
			scanf("%d %d ",&p,&q);
			scanf("%d",&r);
			for(j=1;j<=m;j++) {
				leng[j]=M;
				flg[j]=0;
			}
			leng[p]=0;
			if(r==0) {
				for(j=1;j<=m;j++) {
					min=M;
					for(kk=1;kk<=m;kk++) {
						if(flg[kk]==0 && leng[kk]<min) {
							kaku=kk;
							min=leng[kk];
						}
					}
					flg[kaku]=1;
					for(kk=1;kk<=m;kk++) {
						if((leng[kaku]+kin[kaku][kk])<leng[kk]) leng[kk]=leng[kaku]+kin[kaku][kk];
					}
				}
				printf("%d\n",leng[q]);
			}
			else {
				for(j=1;j<=m;j++) {
					min=M;
					for(kk=1;kk<=m;kk++) {
						if(flg[kk]==0 && leng[kk]<min) {
							kaku=kk;
							min=leng[kk];
						}
					}
					flg[kaku]=1;
					for(kk=1;kk<=m;kk++) {
						if((leng[kaku]+zi[kaku][kk])<leng[kk]) leng[kk]=leng[kaku]+zi[kaku][kk];
					}
				}
				printf("%d\n",leng[q]);
			}
		}
		/*
			//cost
		printf("??????\n");
		printf("      ");
		for(i=1;i<=m;i++) printf("%7d ",i);
		printf("\n");
		printf("\n");
		for(i=1;i<=m;i++) {
			printf("%7d  ",i);
			for(j=1;j<=m;j++) {
				printf("%7d ",kin[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		printf("\n");
		//time
		printf("??????\n");
		printf("      ");
		for(i=1;i<=m;i++) printf("%7d ",i);
		printf("\n");
		printf("\n");
		for(i=1;i<=m;i++) {
			printf("%7d  ",i);
			for(j=1;j<=m;j++) {
				printf("%7d ",zi[i][j]);
			}
			printf("\n");
		}
		printf("\n");*/
	}
		return 0;
}
	