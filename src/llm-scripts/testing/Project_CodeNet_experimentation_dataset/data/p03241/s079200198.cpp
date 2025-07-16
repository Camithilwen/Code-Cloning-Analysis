#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;
using Graph = vector<vector<int>>;

static long long INF = (1LL<<62);

LL N, M;
int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	if(N == 1){
		printf("%lld\n", M);
		return 0;
	}

	vector<LL> D;
	for(LL d = 2; d * d <= M; d++){
		if((M % d) == 0){
			D.push_back(d);
			D.push_back(M/d);
		}
	}
	sort(D.begin(), D.end());

	long long ans = 1;
	for(int i=D.size()-1; i>=0; i--){
		if( (M / D[i]) >= N && D[i] > ans){
			ans = D[i];
		}
	}

	printf("%lld\n", ans);
	return 0;
}
