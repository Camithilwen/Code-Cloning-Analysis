#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e6;
int n,s[N+1],t[N+1];
int hea=1,tai,que[N+1];
int res;
void input(int x[])
{
	static char str[N+2];
	scanf("%s",str+1);
	for(int i=1;i<=n;++i) {
		x[i]=str[i]-'a';
	}
	return;
}
bool check0()
{
	for(int i=1;i<=n;++i) {
		if(s[i]!=t[i]) {
			return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d",&n);
	input(s);
	input(t);
	if(check0()) {
		puts("0");
		return 0;
	}
	for(int spos=n,tpos=n;tpos;--tpos) {
		while((tpos>1)&&(t[tpos-1]==t[tpos])) {
			--tpos;
		}
		while(spos&&((spos>tpos)||(s[spos]!=t[tpos]))) {
			--spos;
		}
		if(!spos) {
			puts("-1");
			return 0;
		}
		while((hea<=tai)&&(que[hea]-(tai-hea+1)+1>tpos)) {
			++hea;
		}
		que[++tai]=spos;
		if(tpos!=1) {
			res=max(res,tai-hea+1);
		}
	}
	++res;
	printf("%d\n",res);
	return 0;
}
