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

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int A, B, C;
	cin >> A >> B >> C;

	if(A < B){
		if(A < C && C < B){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	else{
		if(B < C && C < A){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}