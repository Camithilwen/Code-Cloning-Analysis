#include <bits/stdc++.h>
#define pb push_back
#define cmin(a,b) (a>b?a=b:a)
#define cmax(a,b) (a<b?a=b:a)
#define lop(i,s,t) for(int i=s;i<(t);++i)
#define rep(i,s,t) for(int i=s;i<=(t);++i)
#define dec(i,s,t) for(int i=s;i>=(t);--i)
#define fore(i,v) for(int i=g[v],d=es[i].d;i;i=es[i].nxt,d=es[i].d)
using namespace std;

#define Pr(f,...) //fprintf(stderr,f,##__VA_ARGS__),fflush(stderr)

const int N=5e5+50; 

void read(int &x){
	x=0; 
	char c=getchar(); 
	for(;!isdigit(c);c=getchar()); 
	for(;isdigit(c);c=getchar())x=x*10+c-'0'; 
}

int n,a[N],odd,even,exist;

int gcd(int a,int b){ return !b?a:gcd(b,a%b); }

void maintain(){
	int g=a[1];
	rep(i,2,n)g=gcd(g,a[i]); 
	rep(i,1,n)a[i]/=g;
	odd=even=exist=0; 
	rep(i,1,n){
		odd+=a[i]%2==1;
		even+=a[i]%2==0; 
		exist|=a[i]==1;
	}
}

int main(int argc,char *argv[]){
#ifdef CURIOUSCAT
	//freopen("dat.in","r",stdin);
	//freopen("my.out","w",stdout);
#endif
	read(n); 
	rep(i,1,n)read(a[i]); 
	int cur=1,win; 
	do{
		maintain(); 
		rep(i,1,n)Pr("%d ",a[i]);Pr("\n"); 
		if(even%2==1){
			win=cur;
			break;
		}else if(odd>1){
			win=!cur;
			break;
		}else{
			if(exist){
				win=!cur; 
				break;
			}
			rep(i,1,n)a[i]/=2; 
		}
		cur=!cur; 
	}while(true);
	puts(win==1?"First":"Second"); 
}