#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int data[11][11];
	int n;
	cin >> n;
	while (n){

		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> data[i][j];
			}
		}
		int sum_col[10] = { 0 };
		int sum_low[10] = { 0 };

		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				sum_col[i] += data[i][j];
				sum_low[i] += data[j][i];
			}
			data[i][n] = sum_col[i];
			data[n][i] = sum_low[i];
		}
		int sum = 0;
		for (int i = 0; i < n; i++){
			sum += data[i][n];
		}
		data[n][n] = sum;
		for (int i = 0; i < n + 1; i++){
			for (int j = 0; j < n + 1; j++){
				cout << setw(5) << right << data[i][j];
			}
			cout<<"\n";
		}
		cin >> n;
	}
	
	return 0;	
}