#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(a),_ed=(b);i<=_ed;++i)
#define DREP(i,a,b) for(int i=(a),_ed=(b);i>=_ed;--i)
typedef long long ll;
inline int read(){
    register int x=0,f=1;register char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=0;ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch^'0');ch=getchar();}
    return f?x:-x;
}

const char s[4][7][8]={{"aaba","ccba","abcc","abaa"},
		       {"aa.ab",".bbab","a.cca","a.a.a","bbabb"},
		       {"aaca..","bbca..","ac..aa","ac..bb","..aaca","..bbca"},
		       {"aaca...","bbca...","ac.bb..","ac...aa","..a.abb","..a.a.a","..ccbba"}};

int main(){
    //freopen("in.in","r",stdin);
    int n=read(),k=n%4+4;
    if(n<3)return puts("-1"),0;
    if(n==3)return puts("aab\nb.b\nbaa"),0;
    for(int _=1,j=0;_<=n-k;_+=4,++j){
	int m=j*4;
	REP(t,0,3){
	    REP(i,1,m)putchar('.');
	    REP(i,0,3)putchar(s[0][t][i]);
	    REP(i,m+5,n)putchar('.');
	    puts("");
	}
    }
    int m=k%4;
    REP(t,0,k-1){
	REP(i,1,n-k)putchar('.');
	REP(i,0,k-1)putchar(s[m][t][i]);
	puts("");
    }
    return 0;
}
