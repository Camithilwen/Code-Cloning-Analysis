#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
struct __orz_newbie314159_akioi__{
	int m,inv,a[50010],t[50010];
	void update(int x){while(x<=m)++t[x],x+=x&-x;}
	int query(int x){int r=0;while(x)r+=t[x],x-=x&-x;return r;}
	ll rev;
	void fuck(){
		//1-m -> a
		for(int i=m;i;--i)rev+=query(a[i]),update(a[i]);
	}
}A[2];
int _a[3][100010];
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi();
	for(int i=0;i<3;++i)for(int j=1;j<=n;++j)_a[i][j]=gi();
	for(int i=1;i<=n;++i){
		if(std::max(abs(_a[0][i]-_a[1][i]),abs(_a[1][i]-_a[2][i]))>1)return puts("No"),0;
		int col=(std::min(_a[0][i],_a[2][i])-1)/3+1;
		if(std::max(_a[0][i],_a[2][i])!=col*3||_a[1][i]!=col*3-1)return puts("No"),0;
		if(col-i&1)return puts("No"),0;
		A[i&1].inv+=_a[0][i]>_a[2][i];
		A[i&1].a[++A[i&1].m]=col+1>>1;
	}
	A[0].fuck(),A[1].fuck();
	if(A[0].rev-A[1].inv&1)return puts("No"),0;
	if(A[0].inv-A[1].rev&1)return puts("No"),0;
	puts("Yes");
	return 0;
}
