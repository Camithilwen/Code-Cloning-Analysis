#include <iostream>
using namespace std;

int main(){
	int sales_sum[10];
	int n;
	int sales;
	
	for(;;){
		for(int i = 0; i < 10; i++){
			sales_sum[i] = 0;
		}
		cin >> n;
		if(n == 0) break;
		for(int i = 0; i < n; i++){
			cin >> sales;
			sales_sum[sales]++;
		}
		for(int i = 0; i < 10; i++){
			if(sales_sum[i] == 0){
				cout << '-' << endl;
				continue;
			}
			for(int j = 0; j < sales_sum[i]; j++){
				cout << '*';
			}
			cout << endl;
		}
	}
	
	return 0;
}
		
	
	