#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;

namespace INPUT{
	const int L=1<<15;
	char _buf[L],*S,*T,c;
	char _gc(){
		if(S==T){
			T=(S=_buf)+fread(_buf,1,L,stdin);
			if(S==T) return EOF;
		}
		return *S++;
	}
	void readc(char &c){
		for(c=_gc();c<'a'||c>'z';c=_gc());
	}
	void readi(int &X){
		for(c=_gc();c<'0'||c>'9';c=_gc());X=c&15;
		for(c=_gc();c>='0'&&c<='9';X=X*10+(c&15),c=_gc());
	}
}
#define readc INPUT::readc
#define readi INPUT::readi

const int Maxn=1E6+5;

int N;
char S[Maxn];
char T[Maxn];
int a[Maxn],b[Maxn];

int tap[Maxn];
/*int P[Maxn];
int lnk[Maxn];
int f[Maxn];
*/


bool Check(int X){
	for(int i=1;i+X<=tap[N];++i)
		if(a[i+X]-X<b[i]) return false;
	return true;
}

int main(){
	readi(N); bool flag=true;
	for(int i=1;i<=N;++i) readc(S[i]);
	for(int i=1;i<=N;++i) readc(T[i]);
	for(int i=1;i<=N;++i) flag&=(S[i]==T[i]);
	if(flag){puts("0"); return 0;}
	
	tap[1]=1;
	for(int i=2;i<=N;++i)
		if(T[i]==T[i-1]) tap[i]=tap[i-1],b[tap[i]]=i;
		else tap[i]=tap[i-1]+1;
	/*for(int i=N,j=N;i>=1;--i){
		j=min(j,i);
		while(S[j]!=T[i]&&j>0) --j;
		if(j==0){puts("-1"); return 0;}
		lnk[j]=tap[i];
	}*/
	for(int i=N,j=N;i>=1;--i){
		j=min(j,i);
		while(S[j]!=T[i]&&j>0) --j;
		if(j==0){printf("-1");return 0;}
		a[tap[i]]=j;
	}
	
	int stt,mid,lst;
	stt=0,lst=N+1;
	while(stt+1<lst){
		mid=(stt+lst)>>1;
		if(Check(mid)) lst=mid;
		else stt=mid;
	}
	cout<<lst;
	
	return 0;
}
