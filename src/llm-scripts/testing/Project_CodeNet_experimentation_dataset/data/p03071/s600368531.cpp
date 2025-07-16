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

	int A, B;
	cin >> A >> B;

	int u = A + B;
	int v = A + (A - 1);
	int w = B + (B - 1);

	printf("%d\n", max(u, max(v, w)));
	return 0;
}

