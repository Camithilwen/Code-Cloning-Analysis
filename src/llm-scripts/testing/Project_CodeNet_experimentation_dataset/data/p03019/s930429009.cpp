#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
struct sj{
	int a,l,r;ll x;
	inline sj(){}
	inline sj(int a,int l,int r,ll x):a(a),l(l),r(r),x(x){}
	inline bool operator<(const sj &t)const{return x>t.x;}
}d[N];
inline void cmax(ll &a,ll b){if(a<b)a=b;}
inline ll Y(int i,ll k){
	ll a=d[i].a;
	if(k<=a)return k*d[i].l;
	else    return k*d[i].r+a*(d[i].l-d[i].r);
}
int main(){
	int n,i,a,l,r,x;
	ll L=0ll,R,M,S,g=0ll,t1,t2;
	scanf("%d%d",&n,&x);R=(S=(t1=((ll)x))*n)-1ll;
	for(i=1;i<=n;++i){
		scanf("%d%d%d",&a,&l,&r);t2=a;
		d[i]=sj(a,l,r,t1*r+t2*(l-r));
		g+=l*t2;
	}
	sort(d+1,d+n+1);
	while(L<=R){
		M=(L+R)>>1;
		l=M/x;
		r=M%x;
//		printf("M=%lld l=%d r=%d",M,l,r);
//		for(i=1;i<=n;++i)printf(" (%d,%d)",d[i].x,Y(i,r));
//		printf("\n");
		t1=-1000000000000ll;t2=0ll;
		for(i=1;i<=l;++i){
			t2+=d[i].x;
			cmax(t1,Y(i,r)-d[i].x);
		}
		t1+=d[i].x;
		for(   ;i<=n;++i)cmax(t1,Y(i,r));
		if(t1+t2>=g)R=(S=M)-1ll;else L=M+1ll;
	}
	printf("%lld",S);
	return 0;
}