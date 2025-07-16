#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<set>
#include<stack>
#include<queue>
using namespace std;

int main()
{
 int d,g,p[11],c[11],scr[11][1001]={};
 scanf("%d %d",&d,&g);
 int sm=0;
 for(int i=1;i<=d;i++)
 {
	scanf("%d %d",&p[i],&c[i]);
sm+=p[i];
 }
 for(int i=1;i<=d;i++)
 {
	for(int j=0;j<=sm;j++)
	{
	 //scr[i][j]の最大値はscr[i-1][j]かscr[i-1][j-N]+N*i*100かコンプリートが入るやつか
	 	for(int k=0;k<=min(j,p[i]);k++)
		{
		 if(k==p[i]){scr[i][j]=max(scr[i-1][j],(scr[i-1][j-k]+i*100*k+c[i]));}
		 else{scr[i][j]=max(scr[i-1][j],(scr[i-1][j-k]+i*100*k));}
		}
	}
 }
 for(int i=0;i<=1000;i++)
 {
	if(scr[d][i]>=g){printf("%d",i);break;}
 }
}

