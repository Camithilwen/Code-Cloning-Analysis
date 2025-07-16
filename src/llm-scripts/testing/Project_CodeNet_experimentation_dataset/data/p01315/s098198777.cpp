#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

struct data_t {
	string name;
	double eff;

	bool operator<(const data_t& right) const {
		if (eff == right.eff) {
			return ( name < right.name ) || ( name == right.name );
		}
		else {
			return ( eff > right.eff );
		}
	}
};

int main(void) {
	int N;
	cin >> N;

	while ( N != 0 ) {
		vector<data_t> LS(N);
		vector<int> T(N,0);
		int p,temp,d,e,f,s,m;
		for (int i = 0; i < N; i++) {
			cin >> LS[i].name;
			cin >> p;
			for (int j = 0; j < 3; j++) {
				cin >> temp;
				T[i] += temp;
			}
			cin >> d >> e >> f >> s >> m;
			T[i] += m * (d+e);
			LS[i].eff = (double)((m*f*s)-p)/T[i];
		}

		std::sort(LS.begin(), LS.end());

		for (int i = 0; i < N; i++) {
			cout << LS[i].name << endl;
		}
		cout << "#" << endl;
		cin >> N;
	}

	return 0;
}