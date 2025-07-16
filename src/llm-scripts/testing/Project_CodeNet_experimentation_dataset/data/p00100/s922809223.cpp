#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;

	while (cin >> n, n){
		long long e[5000] = {0}, p, q, t;
		bool out = false, f = false;
		vector<int> s;
		for (int i = 0; i < n; i++){
			cin >> t >> p >> q;
			for (int j = 0; j < s.size(); j++){
				if (s[j] == t){
				 	f = true;
					break;
				}
			}
			if (f == false){
				s.push_back(t);
			}
			e[t] += p * q;
		}
		for (int i = 0; i < s.size(); i++){
			if (e[s[i]] >= 1000000){
				cout << s[i] << endl;
			  out = true;
			}
		}
		if (out == false) cout << "NA" << endl;
	}
	return (0);
}