#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::mt19937 rnd(time(NULL));
#define rand rnd
#define pr std::pair<int,int>
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
#endif
int n,D1,D2,N,x[360001],y[360001],c[2][360001];
std::vector<int>vec[4];
void getcol(int D,int*c){
	int A=1;
	while(D%4==0)D>>=2,A<<=1;
	for(int i=1;i<=N;++i)
		if(D%4==1)c[i]=((x[i]/A)+(y[i]/A))&1;
		else c[i]=(x[i]/A)&1;
}
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	n=gi(),D1=gi(),D2=gi(),N=n*n*4;
	for(int i=1;i<=N;++i)x[i]=(i-1)/(2*n),y[i]=(i-1)%(2*n);
	getcol(D1,c[0]),getcol(D2,c[1]);
	for(int i=1;i<=N;++i)vec[(c[0][i]<<1)|c[1][i]].push_back(i);
	for(int i=0;i<4;++i)
		if(vec[i].size()>=n*n){
			N=n*n;
			for(int j:vec[i]){
				printf("%d %d\n",x[j],y[j]);
				if(!--N)break;
			}
			exit(0);
		}
	return 0;
}
