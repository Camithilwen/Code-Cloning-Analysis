#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int n;
	int area[11][11];
	while(cin >> n){
		if(n == 0) break;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> area[i][j];
			}
		}
		for(int i = 0; i < n; i++){
			int count = 0;
			for(int j = 0; j < n; j++){
				count += area[i][j];
			}
			area[i][n] = count;
		}
		for(int j = 0; j <= n; j++){
			int count = 0;
			for(int i = 0; i < n; i++){
				count += area[i][j];
			}
			area[n][j] = count;
		}
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				cout << setw(5) << area[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}