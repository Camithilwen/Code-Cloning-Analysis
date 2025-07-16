#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lf else if

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> Vi;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=5e6+19;

int D,c,L,a,b,top;
int coe[2][50];
ll val[20],ans;
pair<ll,ll> A[N],B[N];

ll Pow(ll a,int b){
	ll res=1;
	for (;b;b>>=1,a=a*a) if (b&1) res=res*a;
	return res;
}
void dfs_1(int x,ll v,ll coef){
	if (x==top/2){
		A[++a]=mp(v,coef);
		return;
	}
	For(i,-9,10){
		dfs_1(x+1,v+i*val[x],coef*coe[x==0][i+10]);
	}
}
void dfs_2(int x,ll v,ll coef){
	if (x==top){
		B[++b]=mp(v,coef);
		return;
	}
	For(i,-9,10){
		dfs_2(x+1,v+i*val[x],coef*coe[x==0][i+10]);
	}
}
void Main(){
	a=0,b=0;
	top=L/2;
	For(i,0,L) val[i]=Pow(10,L-1-i)-Pow(10,i);
	if (L%2==0){
		dfs_1(0,0,1);
		dfs_2(top/2,0,1);
	} else{
		dfs_1(0,0,L==1?1:10);
		dfs_2(top/2,0,L==1?1:1);
	}
	sort(A+1,A+a+1);
	sort(B+1,B+b+1);
	c=b;
	for (int la=1,ra;la<=a;la=ra+1){
		ll tmp=A[la].se;
		for (ra=la;ra+1<=a&&A[ra+1].fi==A[ra].fi;ra++) tmp+=A[ra+1].se;
		for (;c>=1&&A[la].fi+B[c].fi>D;c--);
		for (;c>=1&&A[la].fi+B[c].fi==D;c--) ans+=tmp*B[c].se;
	}
}

int main(){
	For(a,0,10) For(b,0,10) coe[0][a-b+10]++;
	For(a,1,10) For(b,1,10) coe[1][a-b+10]++;
	D=IN();
	for (L=1;L<=18;L++) Main();
	cout<<ans<<endl;
}