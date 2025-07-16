#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n,field[11][11];
	while (cin >> n, n){
		for (int i = 0; i < 11; i++){
			for (int j = 0; j < 11; j++) field[i][j] = 0;
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++) cin >> field[i][j];
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++) field[n][i] += field[j][i];
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++) field[i][n] += field[i][j];
		}
		for (int i = 0; i < n; i++) field[n][n] += field[n][i];
		for (int i = 0; i <= n; i++){
			for (int j = 0; j <= n; j++)  printf("%5d",field[i][j]);
			puts("");
		}
	}
	return 0;
}