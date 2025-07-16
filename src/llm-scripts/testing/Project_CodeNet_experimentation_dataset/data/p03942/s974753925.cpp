#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define M 1000020
using namespace std;
int read(){
	int nm=0,fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,m,ans,s[M],dt;
char S[M],ch[M];
bool fg=false;
int main(){
	n=read(),scanf("%s%s",S+1,ch+1);
	for(int last=n,i=n;i>0;i--,fg=false){
		m+=s[i+dt];
		while(last>i||(S[last]!=ch[i]&&last)) last--,fg=true;
		if(last<=0){puts("-1");return 0;}
		if(fg&&last<i) m++,s[i+dt]=0,s[last+dt]--,dt++;
		ans=max(ans,m);
	}
	printf("%d\n",ans); return 0;
}