#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

#define V(a) a.begin(), a.end()
typedef set<int> s;

int main()
{
	s a[2], C;

	for (auto &i : a) {
		int n, x;
		cin >> n;
		while (n--) {
			cin >> x;
			i.insert(x);
		}
	}

	set_intersection(V(a[0]), V(a[1]), inserter(C, C.end()));

	cout << C.size() << endl;
}
