#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
	
	int N = 100000;
	
	bool a[100000];
	
	for(int i = 0; i < N; i++){
		a[i] = true;
	}
	
	a[0] = false;
	a[1] = false;
	
	for(int i = 2; i < N; i++){
		if(a[i]){
			for(int j = i * 2; j < N; j += i){
				a[j] = false;
			}
		}
	}
	
	int n;
	
	while(true){
		cin >> n;
		if(n == 0){
			break;
		}else if(n < 5 || n > 10000){
			printf("NA\n");
			continue;
		}else{
			for(int i = n; i > 2; i--){
				if(a[i] && a[i - 2]){
					printf("%d %d\n", i - 2, i);
					break;
				}
			}
		}
	}
	
	return 0;
}