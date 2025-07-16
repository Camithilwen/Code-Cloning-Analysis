#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 300005

char buf[SIZE];
int num_E[SIZE],num_W[SIZE];


int main(){

	int N;
	scanf("%d",&N);
	scanf("%s",buf);

	num_W[0] = 0;
	for(int i = 1; i <= N; i++){

		num_W[i] = num_W[i-1];
		if(buf[i-1] == 'W'){
			num_W[i]++;
		}
	}
	num_E[N+1] = 0;
	for(int i = N; i >= 1; i--){

		num_E[i] = num_E[i+1];
		if(buf[i-1] == 'E'){

			num_E[i]++;
		}
	}

	int ans = N;
	for(int i = 1; i <= N; i++){

		ans = min(ans,num_W[i-1]+num_E[i+1]);
	}

	printf("%d\n",ans);

	return 0;
}
