#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	int budget = min(A, B) + min(C, D);
	cout << budget << endl;
	return 0;
}