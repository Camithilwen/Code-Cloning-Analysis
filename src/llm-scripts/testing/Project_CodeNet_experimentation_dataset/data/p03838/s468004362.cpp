#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstring>
#include <queue>
#include <assert.h>
#include <cmath>
#include <stack>
#include <deque>
#include <set>
#include <unordered_map>
#include <complex>
#include <fstream>
#include <map>
#include <numeric>
#include <functional>
using namespace std;
const int mxn = 1e6+10;
const int mod = 1e9+7;
const int inf = 2e9+10;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int x, y; cin>>x>>y;
	long long ans1 = y>=x? y-x:inf, ans2 = -y>=x? -y-x+1:inf,
	ans3 = y>=-x? y+x+1:inf, ans4 = -y>=-x? -y+x+2:inf;

	cout << min(min(ans1, ans2), min(ans3, ans4)) <<'\n';
	return 0;
}
//comparator function in sorting
//swapping arguments
//missing cases in dp
//dividing in modulo
//Beware of overflow and modulo
//Be mindful of overflow
//s is a matrix but forget
//length of ranges
//working with bit using ull