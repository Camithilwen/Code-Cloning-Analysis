#include <iostream>
#include <fstream>   

using namespace std;

int main() {

	int n, x, t;

	cin >> n >> x >> t;

	int time = 0;
	while (n > 0) {
		time = time + t;
		n = n - x;
	}
	cout << time;

	return 0;
}