#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)


int main() {
	int64_t N;
	cin >> N;
	int64_t ans = 1;
	for(int i=1; i<N; i++) {
		if (i*i<=N) ans = i*i;
		else {
			cout << ans << endl;
			return 0;
		}
	}
	cout << ans << endl;
}