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

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string A, B, C;
	cin >> A >> B >> C;
	if(A[A.size()-1] == B[0] && B[B.size()-1] == C[0]){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}
