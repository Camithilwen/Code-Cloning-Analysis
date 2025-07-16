#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int main (int argc, char *argv[]) {
	int N;
	cin >> N;
	cin.ignore();
	for(int i = 0; i < N; ++i) {
		string str;
		int out_count = 0, base[3] = {0, 0, 0}, point = 0;
		while (true) {
			getline(cin,str);
			if (str == "OUT") out_count++;
			else if (str == "HIT") {
				if (base[2] == 1) {
					point++;
					base[2] = 0;
				}
				base[2] = base[1];
				base[1] = base[0];
				base[0] = 1;
			}
			else if (str == "HOMERUN") {
				point += 1 + count(base,base+3,1);
				memset(base, 0, sizeof base);
			}
			if (out_count == 3) break;
		}
		cout << point << endl;
	}
	return 0;
}