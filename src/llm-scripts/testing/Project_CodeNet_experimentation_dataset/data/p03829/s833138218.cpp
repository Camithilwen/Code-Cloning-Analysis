#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



ll N,A,B;

int main(){

	scanf("%lld %lld %lld",&N,&A,&B);

	ll pre,current;
	scanf("%lld",&pre);

	ll ans = 0;
	for(int i = 1; i < N; i++){
		scanf("%lld",&current);
		if(A*(current-pre) < B){

			ans += A*(current-pre);
		}else{

			ans += B;
		}
		pre = current;
	}

	printf("%lld\n",ans);

	return 0;
}
