#include<iostream>


using namespace std;


int main(){
	int a[10][10];
	int d, i, j, k, temp,sum=0;

	while (1){
		cin >> d;
		if (d == 0){
			return 0;
		}

		for (i = 0, j = 0; i < d; i++){
			for (j = 0; j < d; j++){
				cin >> a[i][j];
			}
		}

		for (i = 0, j = 0; i < d; i++){
			for (j = 0; j < d; j++){
				cout.width(5);
				cout << a[i][j];
			}
			temp = 0;
			for (k = 0; k < d; k++){
				temp += a[i][k];
			}
			cout.width(5);
			cout << temp << endl;
			sum += temp;
		}
			
		

		for (j = 0; j < d; j++){
			temp = 0;
			for (k = 0; k < d; k++){
				temp += a[k][j];
			}
			cout.width(5);
			cout << temp;
			sum += temp;

		}



		cout.width(5);
		cout << sum/2 << endl;
		sum = 0;
	}
}