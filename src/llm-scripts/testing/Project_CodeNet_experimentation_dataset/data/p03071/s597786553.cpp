#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int A, B;
	cin >> A >> B;
	cout << max({ 2 * A - 1, 2 * B - 1, A + B }) << endl;
	return 0;
}