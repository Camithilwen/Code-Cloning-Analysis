#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	while(true){
		int n, k, x, a, b, fee[101][101];
		cin >> n >> k;
		
		if(n == 0 && k == 0){
			break;
		}
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				fee[i][j] = 1000000000;
			}
		}
		
		for(int i = 0; i < k; i++){
			cin >> x >> a >> b;
			
			if(x){
				cin >> fee[a][b];
				fee[b][a] = fee[a][b] = min(fee[a][b], fee[b][a]);
				
				for(int j = 1; j <= n; j++){
					for(int l = 1; l <= n; l++){
						fee[j][l] = min(fee[j][l], fee[j][a] + fee[a][l]);
						fee[l][j] = fee[j][l] = min(fee[j][l], fee[j][b] + fee[b][l]);
					}
				}
			} else{
				if(fee[a][b] != 1000000000){
					cout << fee[a][b] << endl;
				} else{
					cout << -1 << endl;
				}
			}
		}
	}
	return 0;
}