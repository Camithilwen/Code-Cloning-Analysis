#include <iostream>
#include <string>

using namespace std;

int main() {
	int point = 0, hits = 0, out = 0;
	int n; cin >> n;
	
	int i = 0;
	while (i < n) {
		string s; cin >> s;
		if (s == "HIT") {
			hits++;
			if (hits == 4) {
				point++;
				hits--;
			}
		}
		if (s == "OUT") {
			out++;
			if (out == 3) {
				hits = 0;
				out = 0;
				cout << point << endl;
				point = 0;
				i++;
			}
		}
		if (s == "HOMERUN") {
			point += hits + 1;
			hits = 0;
		}
	}
	
	return 0;
}