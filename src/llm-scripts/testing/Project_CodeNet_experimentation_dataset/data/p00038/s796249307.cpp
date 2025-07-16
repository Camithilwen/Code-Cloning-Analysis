#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int l[5];
	char c;
	while (cin >> l[0] >> c >> l[1] >> c >> l[2] >> c >> l[3] >> c >> l[4]) {
		sort(l, l + 5);
		if (l[0] == l[1] && l[1] == l[2] && l[2] == l[3])
			cout << "four card";
		else if (l[4] == l[1] && l[1] == l[2] && l[2] == l[3])
			cout << "four card";
		else if (l[0] == l[1] && l[1] == l[2] && l[4] == l[3])
			cout << "full house";
		else if (l[0] == l[1] && l[3] == l[2] && l[4] == l[3])
			cout << "full house";
		else if (l[4] == l[3] + 1 && l[3] == l[2] + 1 && l[2] == l[1] + 1 && l[1] == l[0] + 1)
			cout << "straight";
		else if (l[0] == 1 && l[1] == 10 && l[2] == 11 && l[3] == 12 && l[4] == 13)
			cout << "straight";
		else if (l[0] == l[1] && l[1] == l[2])
			cout << "three card";
		else if (l[3] == l[1] && l[1] == l[2])
			cout << "three card";
		else if (l[3] == l[4] && l[3] == l[2])
			cout << "three card";
		else if (l[0] == l[1] && l[2] == l[3])
			cout << "two pair";
		else if (l[0] == l[1] && l[4] == l[3])
			cout << "two pair";
		else if (l[2] == l[1] && l[4] == l[3])
			cout << "two pair";
		else if (l[0] == l[1] || l[1] == l[2] || l[2] == l[3] || l[3] == l[4])
			cout << "one pair";
		else cout << "null";
		cout << endl;
	}
}