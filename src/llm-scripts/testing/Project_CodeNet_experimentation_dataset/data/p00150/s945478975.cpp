#include <iostream>
using namespace std;

const int MAX = 10000;
int plist[MAX + 1] = {};

void primeNumber(){
	
	//0 -> prime, 1 -> composite
	
	plist[0] = 1;
	plist[1] = 1;
	
	for(int i = 2; i <= MAX; ++i){
		if(plist[i] == 0){
			int c = i * 2;
			while(c <= MAX){
				plist[c] = 1;
				c += i;
			}
		}
	}
}

int main(){
	int n;
	
	primeNumber();
	
	while(cin >> n, n){
		int k;
		if(n % 2 == 0){
			k = n - 1;
		}else{
			k = n;
		}
		
		while(k >= 3){
			if(plist[k] == 0 && plist[k - 2] == 0){
				cout << k - 2 << " " << k << endl;
				break;
			}
			k -= 2;
		}
	}
	
	return 0;
}