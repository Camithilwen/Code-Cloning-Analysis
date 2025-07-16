#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> vec(4); int his, geo, ans;
	for (int i = 0; i < 4; i++) cin >> vec[i];
	cin >> his >> geo;
	sort(vec.begin(), vec.end(), greater<int>());
	ans = vec[0] + vec[1] + vec[2] + (his > geo ? his : geo);
	cout << ans << endl;
	return 0;
}
