#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	int sum = 0;
	vector<int> vec_1(4); vector<int> vec_2(2);
	for (int i = 0; i < 4; i++) cin >> vec_1[i];
	for (int i = 0; i < 2; i++) cin >> vec_2[i];
	sort(vec_1.begin(), vec_1.end(), greater<int>());
	sort(vec_2.begin(), vec_2.end(), greater<int>());
	for (int i = 0; i < 3; i++) sum += vec_1[i];
	for (int i = 0; i < 1; i++) sum += vec_2[i];
	cout << sum << endl;
	return 0;
}
