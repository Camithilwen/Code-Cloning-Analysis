#include<bits/stdc++.h>
#define pb(a) push_back(a)
#define ms(x,y) memset(x,y,sizeof(x))
#define sci(a) scanf("%d",&a) 
#define scl(a) scanf("%lld",&a)
#define scd(a) scanf("%lf",&a) 
#define ll long long 
using namespace std;
/* --------------- fast io --------------- */ // begin
namespace Fread{
const int SIZE=1<<20;
char buf[SIZE],*S,*T;
inline char getchar(){
	if(S==T){
		T=(S=buf)+fread(buf,1,SIZE,stdin);
		if(S==T)return EOF;
	}
	return *S++;
}
}//namespace Fread
namespace Fwrite{
const int SIZE=1<<20;
char buf[SIZE],*S=buf,*T=buf+SIZE;
inline void flush(){
	fwrite(buf,1,S-buf,stdout);
	S=buf;
}
inline void putchar(char c){
	*S++=c;
	if(S==T)flush();
}
struct _{
	~_(){flush();}
}__;
}//namespace Fwrite

#ifdef ONLINE_JUDGE
	#define getchar Fread::getchar
	#define putchar Fwrite::putchar
#endif

template<typename T>inline void read(T& x){
	x=0;int f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+(c-'0'),c=getchar();
	x*=f;
}
template<typename T>inline void write(T x,bool _enter=0,bool _space=0){
	if (!x)putchar('0');else{
		if(x<0)putchar('-'),x=-x;
		static char dig[41];
		int top=0;
		while(x)dig[++top]=(x%10)+'0',x/=10;
		while(top)putchar(dig[top--]);
	}
	if(_enter)putchar('\n');
	if(_space)putchar(' ');
}

namespace Fastio{
struct reader{
	template<typename T>reader& operator>>(T& x){::read(x);return *this;}
	reader& operator>>(char& c){
		c=getchar();
		while(c=='\n'||c==' ')c=getchar();
		return *this;
	}
	reader& operator>>(char* str){
		int len=0;
		char c=getchar();
		while(c=='\n'||c==' ')c=getchar();
		while(c!='\n'&&c!=' ')str[len++]=c,c=getchar();
		str[len]='\0';
		return *this;
	}
}cin;
const char endl='\n';
struct writer{
	template<typename T>writer& operator<<(T x){::write(x,0,0);return *this;}
	writer& operator<<(char c){putchar(c);return *this;}
	writer& operator<<(const char* str){
		int cur=0;
		while(str[cur])putchar(str[cur++]);
		return *this;
	}
}cout;
}//namespace Fastio
#define cin Fastio::cin
#define cout Fastio::cout
#define endl Fastio::endl
/* --------------- fast io --------------- */ // end

const int maxn=100005;
int main(){
		//#define int ll
		int d,t,s;
	while(scanf("%d %d %d",&d,&t,&s)!=EOF){

		
		if(t*s>=d)
			puts("Yes");
		else
			puts("No");
	 }
	return 0;
} 