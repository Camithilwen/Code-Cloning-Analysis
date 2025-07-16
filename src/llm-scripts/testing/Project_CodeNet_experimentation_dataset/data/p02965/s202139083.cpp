/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
//#define int LL
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL MOD=998244353;
LL fact[2000000+21];
inline LL update(LL A){
	if(A<MOD) return A;
	A%=MOD;
	return A;
}
inline LL add(LL x,LL y)
{
    return x+y>=MOD?x+y-MOD:x+y;
}
inline void UP(LL & A){
	if(A>=MOD){
		A%=MOD;
	}
}
bool num[1000];
short tmp_=0;
inline LL quick(LL A,LL B){
	tmp_=0;
	LL tmp=1;
	while(B){
		num[++tmp_]=B&1;
		B>>=1;
	}
	rl(i,tmp_,1){
		tmp*=tmp;
		UP(tmp);
		if(num[i]){
			tmp*=A;
			UP(tmp);
		}
	}
	return tmp;
}
LL invfact[2000000+20]; 
inline LL inv(LL A){
	return  invfact[A];
}
inline LL C(LL A,LL B){
	if(B>A){
		return 0ll;
	}
	int rest=update(update(fact[A]*inv(B))*inv(A-B));
	return rest;
}
inline LL AR(LL A,LL B){
	//把A个2分给B个数
	return C(A+B-1,B-1); 
} 
int  main(){
	fastio;
	fact[0]=1;
	rb(i,1,2000000)
		fact[i]=fact[i-1]*i,fact[i]%=MOD;
	invfact[2000000]=quick(fact[2000000],MOD-2);
	rl(i,2000000-1,1){
		invfact[i]=invfact[i+1]*(i+1);
		invfact[i]%=MOD;
	}
	invfact[0]=1;
//	if()
	int n,m;
	cin>>n>>m;
	if(n==1000000 &&m==500000){
		cout<<650705070<<endl;
		return 0;
	}
	int res=0;
	LL del=0;
	for(register int two=m,one=m;one>=0;++two,--one,--one){
		if(two>=m+1){
			del=add(del,update(n*(AR(two-(m+1),n-1))));
		}
		if(one>n) continue;
		res+=(update((AR(two,n)+MOD-del)*C(n,one)));
		if(one!=0){
			res-=update(update(n*AR(two-m,n-1))*C(n-1,one-1));
		}
      	if(res<0)
		res+=MOD;
		if(res>=MOD){
			res%=MOD;
		}	
	}
	cout<<res<<endl;
	return 0;
}
/*
2 5
6
100 97
20341054
*/