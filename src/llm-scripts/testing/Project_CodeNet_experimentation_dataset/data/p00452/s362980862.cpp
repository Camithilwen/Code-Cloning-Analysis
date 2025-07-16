#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

#define MAX_N 1000

using namespace std;

int p[MAX_N + 1];
vector<int > lat;

int N;
int M;

int solve(){
	int res = 0;
	int fake;

	sort(p,p + N + 1);
	for(int i = 0;i <= N;i++){
		for(int j = i;j <= N;j++){
			lat.push_back(p[i] + p[j]);
		}
	}

	sort(lat.begin(),lat.end());
	vector<int >::iterator ite;

	for(int i = 0;i <= N;i++){
		for(int j = 0;j <= N;j++){
			fake = M - (p[i] + p[j]);
			if(fake < 0) break;
			ite = upper_bound(lat.begin(),lat.end(),fake);
			res = max(res,p[i] + p[j] + *(ite - 1));
		}
	}

	return res;
}
			
			

int main(){

	while(true){
	scanf("%d%d",&N,&M);
	if(N == 0 && M == 0) break;
	lat.clear();
	for(int i = 1;i <= N;i++){
		scanf("%d",p + i);
	}

	int ans = solve();

	printf("%d\n",ans);

	}
}