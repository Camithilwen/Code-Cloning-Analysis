/*
{

AuThOr Gwj
*/
#pragma GCC optimize(2)
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define int LL
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n,a[200000+20];
double a_[200000+20];
int all[65][65];
signed main(){
	fastio;
	R(n);
	LL res=0;
	rb(i,1,n){
		R(a_[i]);
		;
		a[i]=llround(a_[i]*=1000000000.0);
		int A,B;
		A=B=0;
		while(a[i]%5==0){
			a[i]/=5;
			A++;
		}
		while(a[i]%2==0){
			a[i]/=2;
			B++;
		}
//		cout<<A<<" "<<B<<endl;
		rb(k,0,64)
			rb(j,0,64){
				if(k+A>=18&&j+B>=18){
					res+=all[k][j];
				}
		}
		all[A][B]++;
	}	
	cout<<res<<endl;
	return 0;
}


