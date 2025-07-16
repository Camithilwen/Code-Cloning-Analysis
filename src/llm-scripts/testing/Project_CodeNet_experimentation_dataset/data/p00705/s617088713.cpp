#include <iostream>
using namespace std;

int main(){
	int n,q;
	bool x[50][100];
	while(cin >> n >> q,n||q){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < 100; j++) x[i][j] = false;
		}
		for(int i = 0; i < n; i++){
			int m;
			cin >> m;
			for(int j = 0; j < m; j++){
				int date;
				cin >> date;
				x[i][date] = true;
			}
		}
		bool ok = true;
		int sum = -1, ans;
		for(int i = 1; i < 100; i++){
			int cnt = 0;
			for(int j = 0; j < n; j++){
				if(x[j][i]) cnt++;
			}
			if(cnt > sum){
				sum = cnt;
				ans = i;
			}
		}
		if(sum >= q) cout << ans << endl;
		else cout << 0 << endl;
	}
}