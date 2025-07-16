#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> v(3);
	for(int &e : v) cin >> e;

	sort(v.begin(), v.end());
	cout << v[0] + v[1];

}
