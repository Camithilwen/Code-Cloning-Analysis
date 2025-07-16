#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;
// a>=0, b>=0, x*a+y*b=gcd>=0, a>0,b>0=>abs(y)<=a,abs(x)<=b
LL gcdex(LL a,LL b,LL& x, LL& y){
	LL ax=1,ay=0;
	LL bx=0,by=1;
	while(b){
		LL r=a/b;
		LL t=a-r*b; a=b; b=t;
		LL tx=ax-r*bx; ax=bx; bx=tx;
		LL ty=ay-r*by; ay=by; by=ty;
	}
	x=ax;
	y=ay;
	return a;
}
LL modinv(LL a, LL m){
	LL x,y;
	gcdex(a,m,x,y);
	if(x<0){
		x+=m;
	} else if(x>=m){
		x-=m;
	}
	return x;
}
const int M=1e9+7;
LL cm[1001][1001];
LL dp[1001][1001];
LL rev[1001];
int main() {
	for(int i=0;i<1001;i++){
		cm[i][0]=1;
		for(int j=1;j<=i;j++){
			cm[i][j]=(cm[i-1][j-1]+cm[i-1][j])%M;
		}
	}
	for(int i=1;i<1001;i++){
		rev[i]=modinv(i,M);
	}

	int N,A,B,C,D;
	scanf("%d%d%d%d%d",&N,&A,&B,&C,&D);
	dp[0][A-1]=1;
	for(int i=0;i<=N;i++){
		for(int j=A;j<=B;j++){
			dp[i][j]+=dp[i][j-1];
			LL c=1;
			LL r=i;
			for(int k=1;k<=D;k++){
				c*=cm[r][j]*rev[k]%M;
				c%=M;
				r-=j;
				if(r<0)break;
				if(C<=k){
					dp[i][j]+=c*dp[r][j-1]%M;
					dp[i][j]%=M;
				}
			}
		}
	}
	printf("%lld\n",dp[N][B]);

	return 0;
}

