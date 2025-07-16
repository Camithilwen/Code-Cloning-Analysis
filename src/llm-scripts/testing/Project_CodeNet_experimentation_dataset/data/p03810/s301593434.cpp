#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int N=1000100,P=1e9+7;
inline int read(){
	int x=0,f=0,c=getchar();
	for(;c>'9'||c<'0';f=c=='-',c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
	x=(x<<1)+(x<<3)+c-'0';return f?-x:x;
}
inline void write(ll x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);putchar(x%10+'0');
}
int n,a[N];
int dfs(int x){
	int sm=0,i;
	for(i=1;i<=n;i++)
		sm^=a[i]&1;
	if(sm!=(n&1))return x;
	for(i=1;i<=n;i++)
	if(a[i]&1&&a[i]>1)break;
	a[i]--;
	sm=a[1];
	for(i=2;i<=n;i++)sm=__gcd(a[i],sm);
	if(sm&1)return !x;
	for(i=1;i<=n;i++)a[i]/=sm;
	return dfs(!x);
}
int main(){
	//freopen("1.out","w",stdout);
	int i;
	n=read();
	for(i=1;i<=n;i++)a[i]=read();
	puts(dfs(1)?"First":"Second");
	return 0;
}