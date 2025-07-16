#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<tuple>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-15
#define mp(a1,a2) make_pair(a1,a2)
#define YMAX 250001
typedef long long ll;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
bool arr[10001];
int Nmax=10001;
vint sosu;
void Eratosthenes(){
	for(int i = 0; i < Nmax; i++){
		arr[i] = true;
	}
	arr[0]=false; arr[1]=false;
	for(int i = 2; i < sqrt(Nmax); i++){
		if(arr[i]){
			for(int j = 0; i * (j + 2) < Nmax; j++){
				arr[i *(j + 2)] = false;
			}
		}
	}
	rep1(i,Nmax){
		if(arr[i]) sosu.push_back(i);
	}
}
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
ll lcm(ll x,ll y){
	return x/gcd(x,y)*y;
}
int main(){
	Eratosthenes();
	int N;
	ll a[502][502];
	ll ichimatsu1[501][501],ichimatsu2[501][501];
	scan(N);
	int NMAX=500;
	int sosucount=0;
	for(int kyori=0;kyori<=NMAX*2-2;kyori+=2){
		for(int j=0;j<=NMAX-1;j++){
			int i=kyori-j;
			if(i<0||i>NMAX-1) continue;
			//printf("kyori:%d i:%d j:%d sosu:%d\n",kyori,i,j,sosu[sosucount]);
			ichimatsu1[i][j]=sosu[sosucount];
		}
		sosucount++;
	}
	for(int kyori=NMAX-1;kyori<=NMAX*2-2&&kyori>=0;kyori+=(kyori<=NMAX-1 ? 2*(NMAX-1-kyori)+2 : 2*(NMAX-1-kyori))){
		for(int j=NMAX-1;j>=0;j--){
			int i=j-kyori+NMAX-1;
			if(i<0||i>NMAX-1) continue;
			ichimatsu2[i][j]=sosu[sosucount];
		}
		sosucount++;
	}
	/*rep(i,N){
		rep(j,N){
			if((i+j)%2==0) printf("%lld ",ichimatsu1[i][j]);
			else printf("-- ");
		}
		kaigyo;
	}
	kaigyo;
	rep(i,N){
		rep(j,N){
			if((i+j)%2==0) printf("%lld ",ichimatsu2[i][j]);
			else printf("-- ");
		}
		kaigyo;
	}*/
	rep(i,NMAX){
		rep(j,NMAX){
			if((i+j)%2==0) a[i+1][j+1]=ichimatsu1[i][j]*ichimatsu2[i][j];
		}
	}
	rep(i,NMAX+2){
		a[i][0]=1;
		a[i][NMAX+1]=1;
	}
	rep(j,NMAX+2){
		a[0][j]=1;
		a[NMAX+1][j]=1;
	}
	rep(i,NMAX){
		rep(j,NMAX){
			if((i+j)%2==1) a[i+1][j+1]=lcm(lcm(a[i][j+1],a[i+2][j+1]),lcm(a[i+1][j],a[i+1][j+2]))+1;
		}
	}
	rep1(i,N){
		rep1(j,N){
			printf("%lld ",a[i][j]);
		}
		kaigyo;
	}
	return 0;
}
