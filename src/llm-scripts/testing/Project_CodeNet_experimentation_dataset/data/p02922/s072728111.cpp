#include<iostream>
using namespace std;
int main() {
	int A, B;
	cin >> A >> B;
	int ans = 0;
	if (B == 1) {
		
	}
	else {
		for (int i = 1; i < 100; i++) {
			if (i * A - i + 1 >= B) {
				ans = i;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}