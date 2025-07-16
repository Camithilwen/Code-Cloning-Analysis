#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <functional>
#include <iomanip>
#include <bitset>
#include <numeric>
#include <queue>
#include <map>
#include <cstdint>
#include <set>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
const long long mod = 1000000007;
typedef long long int ll;
typedef pair<ll, ll> P;
const vector<int> di = { -1, 0, 1, 0 };
const vector<int> dj = { 0, 1, 0, -1 };
const double PI = 3.14159265358979323846;


int main() {

	int x;
	cin >> x;
	int five_hund = 0;
	int five = 0;

	five_hund = x / 500;
	five = (x % 500) / 5;

	cout << five_hund * 1000 + five * 5 << endl;


	return 0;

}

