#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<bitset>
#include<string>
#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sstream>
#include<numeric>
#include<iostream>
#include<algorithm>
#include<functional>

#define For(i,x,y) for (int i=x;i<y;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define dprintf(...) fprintf(stderr,__VA_ARGS__)
using namespace std;

typedef long long ll;
typedef double db;
typedef vector<int> Vi;
typedef pair<int,int> pii;

int IN(){
	int c,f,x;
	while (!isdigit(c=getchar())&&c!='-');c=='-'?(f=1,x=0):(f=0,x=c-'0');
	while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return !f?x:-x;
}

const int N=1e5+19;

int A[3][N];
int n,rev[2];
Vi V[2];

int C[N];
void Add(int x){
	for (;x<N;x+=x&-x) C[x]++;
}
int Qry(int x){
	int res=0;
	for (;x;x-=x&-x) res+=C[x];
	return res;
}
ll calc(int t){
	ll res=0;
	memset(C,0,sizeof(C));
	for (int i=V[t].size()-1;~i;i--){
		res+=Qry(V[t][i]+1);
		Add(V[t][i]+1);
	}
	return res;
}

int main(){
	n=IN();
	For(i,0,3) For(j,0,n) A[i][j]=IN()-1;
	For(i,0,3) For(j,0,n){
		if (A[i][j]/3!=A[0][j]/3) return puts("No"),0;
		if ((A[i][j]/3)%2!=j%2) return puts("No"),0;
	}
	For(i,0,n){
		if (A[1][i]%3!=1) return puts("No"),0;
		if (A[0][i]%3!=0) rev[i&1]++;
		V[i&1].pb(A[0][i]/3);
	}
	if (calc(0)%2!=rev[1]%2) return puts("No"),0;
	if (calc(1)%2!=rev[0]%2) return puts("No"),0;
	puts("Yes");
}