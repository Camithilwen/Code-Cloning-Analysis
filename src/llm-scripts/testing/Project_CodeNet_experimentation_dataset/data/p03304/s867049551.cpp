#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#include<deque>
#include<iomanip>
#include<tuple>
#include<stack>

#define _USE_MATH_DEFINES
#include<math.h>


using namespace std;
typedef long long ll;

typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef tuple<int, int, int> ti3;

const ll MOD_CONST = 1000000007;
//const ll MOD_CONST = 998244353;


const int BIG_NUM = 1000000005;
const ll INF = 1000000000000000000;

//const vector<vector<int>> DIR{ {1,0},{0,1},{-1,0},{0,-1} };

//const double EPS = 1e-10;


int main() {
	int n, m, d;
	cin >> n >> m >> d;
	double p = (d == 0) ? 1.0 / n : (2.0 * (n - d)) / n / n;
	std::cout << setprecision(20) << p * (m - 1) << endl;
} 


