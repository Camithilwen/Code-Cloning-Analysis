#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
#include <deque>
#include <queue>
#include <list>
using namespace std;
typedef long long ll;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
	int a[3], k, b = 0;
	for (int i = 0 ; i < 3 ; i++) cin >> a[i];
	cin >> k;
	sort(a, a + 3);
	b = a[2];
	for (int i = 0 ; i < k ; i++) b *= 2;
	cout << a[0] + a[1] + b;  
}