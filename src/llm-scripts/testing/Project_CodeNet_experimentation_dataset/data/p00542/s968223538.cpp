#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	int A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >> F;
	cout << max(E, F) + max({ A + B + C, A + B + D, A + C + D, B + C + D }) << endl;
}
