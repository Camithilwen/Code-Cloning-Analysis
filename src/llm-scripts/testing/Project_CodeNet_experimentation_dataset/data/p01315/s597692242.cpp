#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct data_t {
	string name;
	double eff;

	bool operator<(const data_t& right) const {
		if (eff == right.eff) {
			return (name < right.name);
		}
		else {
			return (eff > right.eff);
		}
	}
};

int main(void) {
	int N;
	while (cin >> N, N) {
		vector<data_t> data(N);
		int p,temp,d,e,f,m,s;
		for (int i = 0; i < N; ++i) {
			cin >> data[i].name;
			cin >> p; 
			int time = 0;
			for (int i = 'A'; i <= 'C'; ++i) {
				cin >> temp;
				time += temp;
			}
			cin >> d >> e >> f >> s >> m;
			time += m * (d + e);
			data[i].eff = (double)((f * m * s) - p)/(double)time;
		}

		sort(data.begin(),data.end());

		for (int i = 0; i < N; ++i) {
			cout << data[i].name << endl;
		}
		cout << "#" << endl;
	}
	return 0;
}