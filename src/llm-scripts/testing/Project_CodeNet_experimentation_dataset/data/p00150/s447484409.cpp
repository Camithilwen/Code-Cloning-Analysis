#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cctype>
#include<complex>
#include<iostream>
#include<sstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>

using namespace std;
const int dx[] = {1,0,-1,0},dy[] = {0,1,0,-1};
#define INF 999999
#define rep(i,j) for(int i=0;i<(j);++i)
#define reps(i,j,k) for(int i=j;i<k;++i)
typedef long long ll;
typedef unsigned long long ull;
bool us[100100]={false};
int p[100100]={0};
int main(){
	/*Eratosthenes*/
	p[2] = 2;
	for(int i = 0; i < 100101 ; i+=2)us[i] = true;
	for(int i = 3; i < 100101; i+=2){
		if(us[i] == true)continue;
		else if(us[i] == false){
			p[i] = i;
			for(int j = i+i; j < 100101; j += i)us[j] = true;
		}
	}

	int n;

	while(scanf("%d",&n),n){
		for(int i = n; i >= 0; i--){
			if(!us[i] && !us[i-2]){
				printf("%d %d\n",p[i-2],p[i]);
				break;
			}
		}
	}
	return 0;
}