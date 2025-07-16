#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cmath>
#include <queue>

using namespace std;

int main(){
	
	int n, m;
	
	while(true){
		
		cin >> n >> m;
		
		if(n == 0 && m == 0){
			break;
		}
		
		int p[200000];
		
		long long int sum = 0;
		
		for(int i = 0; i < n; i++){
			cin >> p[i];
			sum += p[i];
		}
		
		sort(p, p + n);
		
		for(int i = n - m; i >= 0; i -= m){
			sum -= p[i];
		}
		
		cout << sum << endl;
		
	}
	
	return 0;
}