#include<iostream>
#include<vector>
using namespace std;
int num_2(int a) {
	int ret=0;
	while (a % 2 == 0) {
		ret++;
		a /= 2;
	}
	return ret;
}
int even(vector<vector<int>> a) {
	int ret = a.at(1).at(0);
	for (int i = 0; i < a.at(0).size(); i++) {
			if (ret > a.at(1).at(i))ret = a.at(1).at(i);
	}
	return ret;
}
int main() {
	int n;
	cin >> n;
	vector<vector<int>> a(2,vector<int> (n));
	for (int i = 0; i < n; i++) {
		cin >> a.at(0).at(i);
	}
	for (int i = 0; i < n; i++) {
		a.at(1).at(i) = num_2(a.at(0).at(i));
	}
	cout << even(a) << endl;

}