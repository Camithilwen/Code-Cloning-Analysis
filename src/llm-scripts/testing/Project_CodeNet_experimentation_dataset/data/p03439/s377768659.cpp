#include <iostream>
using namespace std;

void ask(int left, int right, bool male) {
	int mid = (left + right) / 2;
	cout << mid << endl;
	string s;
	cin >> s;
	if (s == "Vacant") return;
	if (((mid - left) % 2 == 0) == (male == (s == "Male"))) ask(left, mid - 1, male);
	else ask(mid + 1, right, s == "Male");
}

int main() {
	int N;
	cin >> N;
	cout << 0 << endl;
	string s;
	cin >> s;
	if (s == "Vacant") return 0;
	ask(1, N - 1, s == "Male");
	return 0;
}