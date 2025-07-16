#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	/*int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		vector<int>v(n);
		for (int i = 0; i < n; i++){
			cin >> v[i];
		}
		if (n % 2){
			reverse(v.begin(), v.end());
			swap(v[n / 2], v[n / 2 - 1]);
		}
		else reverse(v.begin(), v.end());
		for (int i : v)cout << i << " ";
		cout << '\n';
	}*/
	double a, b, c;
	cin >> a >> b >> c;
	int count = ceil(a/b)*c;
	cout << count << '\n';
	//system("pause");
	return 0;
}
