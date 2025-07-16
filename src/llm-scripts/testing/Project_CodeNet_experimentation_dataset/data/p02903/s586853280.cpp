#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <numeric>
#include <math.h> 

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, a, b, i, j;
	cin >> n >> m >> b >> a;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if ((i < a) + (j < b) == 1) cout << "1";
			else cout << "0";
		}
		cout << "\n";
	}

	return 0;
}


