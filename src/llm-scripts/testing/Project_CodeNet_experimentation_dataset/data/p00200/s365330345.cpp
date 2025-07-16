#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>

#define INF 1<<30-1

using namespace std;

int n;
int c[101][101];
int t[101][101];
int flg;

int washa(int st,int en,int va){
	if(flg==1){
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(c[i][j]>c[i][k]+c[k][j]){
						c[i][j]=c[i][k]+c[k][j];
					}
					if(t[i][j]>t[i][k]+t[k][j]){
						t[i][j]=t[i][k]+t[k][j];
					}
				}
			}
		}
		flg=0;
	}
	if(va==0){
		return c[st][en];
	}else{
		return t[st][en];
	}
}

int main(){
	while(1){
		int m;
		for(int i=0;i<101;i++){
			for(int j=0;j<101;j++){
				c[i][j]=t[i][j]=INF;
			}
		}
		flg=1;
		
		scanf("%d%d",&m,&n);
		if(m==0 && n==0){
			break;
		}
		for(int i=0;i<m;i++){
			int a,z,s,x;
			scanf("%d%d%d%d",&a,&z,&s,&x);
			c[a][z]=c[z][a]=s;
			t[a][z]=t[z][a]=x;
		}
		
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			int a,z,s;
			scanf("%d%d%d",&a,&z,&s);
			
			printf("%d\n",washa(a,z,s));
		}
	}
}