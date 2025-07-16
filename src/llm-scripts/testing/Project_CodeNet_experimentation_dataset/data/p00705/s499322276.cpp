#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <cstring>
#include <cctype>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <complex>
using namespace std;
const int INF = 1<<28;

int main() {
	int n, q;
	while(cin >> n >> q, n|q) {
		int days[100] = {};
		for(int i=0; i<n; i++) {
			int num;
			cin >> num;
			for(int j=0; j<num; j++) {
				int temp;
				cin >> temp;
				days[temp]++;
			}
		}
		int  ans = 0;
		for(int i=0; i<100; i++)
			if(days[i] >= q && days[i] > days[ans])
				ans = i;
		cout << ans << endl;
	}

	return 0;
}