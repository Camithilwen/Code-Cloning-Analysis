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

int s[5];

int ans=-1;
string x;
int flg=0;
void wf(int i,int w ,int z) //i文字目までの部分和w zで＋と－の状況を管理
{
  if(flg==1){return;}
  int g,h;
  //+を挿入した場合の処理
 g=w+s[i]; h=z*10+1; if(i!=4){wf(i+1,g,h);} if(i==4&&g==7){ans=h; flg=1; return;}
  //-を挿入した場合の処理
 g=w-s[i]; h=z*10; if(i!=4){wf(i+1,g,h);} if(i==4&&g==7){ans=h;flg=1; return;}
}
int main()
{
 cin>>x;
 for(int i=1;i<=4;i++)
 {
	s[i]=x[i-1]-'0';
 }
 wf(2,s[1],0);
 //ansを解読する作業
 int dx=100;
 for(int i=1;i<4;i++)
 {
	printf("%d",s[i]);
	if(ans>=dx){printf("+");ans=ans-dx;}
	else {printf("-");}
	dx=dx/10;
 }
 printf("%d=7",s[4]);
}