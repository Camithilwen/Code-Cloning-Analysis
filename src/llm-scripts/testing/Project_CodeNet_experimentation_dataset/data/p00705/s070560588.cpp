#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, q, m, mx, t, s;
	bool a[51][101], f;
	
	while(1){
		cin >> n >> q;
		if(n == 0 && q == 0){
			break;
		}
		mx = 0;
		fill(&a[0][0], &a[50][100], false);
		
		for(int i = 0; i < n; i++){
			cin >> m;
			for(int j = 0; j < m; j++){
				cin >> t;
				a[i][t] = true;
			}
			if(t > mx){
				mx = t;
			}
		}
		m = 0;
		f = true;
		for(int i = 1; i <= mx; i++){
			t = 0;
			for(int j = 0; j < n; j++){
				if(a[j][i]){
					t++;
				}
			}
			if(m < t){
				m = t;
				s = i;
			}
		}
		
		if(m >= q){
			cout << s << endl;
		} else {
			cout << 0 << endl;
		}
	}
	
	return 0;
}