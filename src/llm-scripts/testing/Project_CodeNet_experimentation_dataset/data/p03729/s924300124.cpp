#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <tuple>
#include<map>

using namespace std;
int main() {
	string A, B, C;
	cin >> A >> B >> C;

	bool ans = true;

	if (A.at(A.size() - 1) != B.at(0)) ans = false;
	if (B.at(B.size() - 1) != C.at(0)) ans = false;

	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;

}