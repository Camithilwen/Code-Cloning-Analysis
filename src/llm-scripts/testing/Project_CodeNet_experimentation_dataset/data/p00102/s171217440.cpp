#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n, h[11][11];
	while(scanf("%d", &n)){
		if(!n)break;
		for(int i = 0;i < n;i++){
			int num = 0;
			for(int j = 0;j < n;j++){
				scanf("%d", &h[i][j]);
				num += h[i][j];
				printf("%5d", h[i][j]);
			}
			h[i][n] = num;
			printf("%5d\n", num);
		}
		
		for(int i = 0;i <= n;i++){
			int num = 0;
			for(int j = 0;j < n;j++)num += h[j][i];
			printf("%5d", num);
		}
		printf("\n");
	}
}