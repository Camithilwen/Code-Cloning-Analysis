#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q;
	while(cin >> n  >> q && (n || q)){
		int cnt[1000] = {0}, m, d;
		for(int i = 0; i < n; ++i){
			cin >> m;
			for(int j = 0; j < m; ++j){
				cin >> d;
				cnt[d]++;
			}
		}
		int maxium = 0, day = 0;
		for(int i = 1; i <= 100; ++i){
			if(maxium < cnt[i]){
				day = i;
				maxium = cnt[i];
			}
		}
		if(maxium >= q)
			cout << day << endl;
		else
			cout << "0" << endl;
	}
	return 0;
}