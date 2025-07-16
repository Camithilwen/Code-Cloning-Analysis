#include<iostream>
#include<string>
using namespace std;

int main() {
	int a, b; cin >> a >> b;

	int ans = 0;
	for (int i = a; i <= b; i++) {
		string a_tmp, b_tmp;
		string ch = to_string(i);
		for (int j = 0; j < ch.size(); j++) {
			a_tmp.push_back(char(ch[j]));
			b_tmp.push_back(char(ch[ch.size() - j-1]));
		}
		if (a_tmp == b_tmp)ans++;
	}
	cout << ans << endl;

	return 0;
}