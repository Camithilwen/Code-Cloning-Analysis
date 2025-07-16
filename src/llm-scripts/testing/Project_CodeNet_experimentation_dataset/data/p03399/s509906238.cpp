#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9+1;
const int MOD = 2e9 + 9;
const ll LINF = 1e18;
using namespace std;

int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << min(a, b) + min(c, d);
	return 0;
}