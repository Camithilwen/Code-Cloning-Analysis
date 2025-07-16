#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int n,sum=0,sumy=0;
	while (1){
		sum = 0;
		sumy = 0;
		cin >> n;
		if (n == 0)break;
		int ma[101][101] = { 0 };
		for (int i = 0; i < n; i++){
			sum = 0;
			for (int i2 = 0; i2 < n; i2++){
				cin >> ma[i][i2];
				sum += ma[i][i2];

			}
			sumy += sum;
			ma[i][n] += sum;
		}
		ma[n][n] += sumy;
		for (int i = 0; i < n; i++){
			sum = 0;
			for (int i2 = 0; i2 < n; i2++){
				sum += ma[i2][i];
				sumy += sum;
			}
			ma[n][i] += sum;
		}
		n++;
		for (int i = 0; i < n; i++){
			for (int i2 = 0; i2 < n; i2++){
				printf("%5d", ma[i][i2]);
			}
			cout << endl;
		}
	}
}