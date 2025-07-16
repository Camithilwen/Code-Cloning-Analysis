#include <iostream>

#define N 1000

using namespace std;

int main(){
	int data[N];
	int n , sum[N];
	int e[N] , p , q;

	while(1){
		int flag = 0;
		
		cin >> n;
		if(n == 0) break;
	
		for(int i = 0; i < n; i++){
			cin >> e[i] >> p >> q;
			sum[i] = p * q;
		
		}for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				if(e[i] == e[j]){
					sum[i] += sum[j];
				}
			}
		}for(int i =  0; i < n; i++){
			if(sum[i] >= 1000000){
				flag = 1;
				cout << e[i] << endl;
			}
		}if(flag == 0){
			cout << "NA" << endl;
		}
	}
	
	return 0;
}