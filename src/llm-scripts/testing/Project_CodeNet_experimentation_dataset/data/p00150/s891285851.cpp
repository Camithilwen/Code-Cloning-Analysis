#include<iostream>
#include<algorithm>
using namespace std;

int main(){

	int n, prime[10001], p[10001];

	fill(prime, prime+10001, 1);
	fill(p, p+10001, 0);
	
	prime[0] = 0;
	prime[1] = 0;
	for(int i=2; i<10001; i++){
		if(prime[i] == 1){
			if(prime[i-2] == 1) p[i] = 1;
			for(int j=2; i*j<10001; j++){
				prime[i*j] = 0;
			}
		}
	}
	
	while(cin >> n){
		if(n == 0) break;
		for(int i=n; i>0; i--){
			if(p[i] == 1) {
				cout << i-2 << " " << i << endl;
				break;
			}
		}
	}
	
	return 0;

}