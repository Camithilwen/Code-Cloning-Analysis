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


int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int A, B, C, D;
	int L, R;
	cin >> A >> B >> C >> D;

	L = A + B;
	R = C + D;

	if(L > R){
		printf("Left\n");
	}
	else if(L == R){
		printf("Balanced\n");
	}
	else{
		printf("Right\n");
	}
	return 0;
}

