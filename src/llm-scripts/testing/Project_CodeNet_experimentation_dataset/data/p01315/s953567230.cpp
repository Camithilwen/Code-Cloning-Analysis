#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<double, string>>x;

int n; double P, A, B, C, D, E, F, S, M; string L;
int main() {
	while (true) {
		x.clear();
		cin >> n;
		if (n == 0) { break; }
		for (int i = 0; i < n; i++) {
			cin >> L >> P >> A >> B >> C >> D >> E >> F >> S >> M;
			x.push_back(make_pair(100000000.00 - ((F*S*M - P) / (A + B + C + (D + E)*M)), L));
		}
		sort(x.begin(), x.end());
		for (int i = 0; i < n; i++) { cout << x[i].second << endl; }
		cout << "#" << endl;
	}
}