#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cmath>
#include <queue>

using namespace std;

int main(){
	
	int n;
	
	while(true){
		cin >> n;
		if(n == 0){
			break;
		}
		
		for(int i = 0; i < n; i++){
			int a, b, c;
			cin >> a >> b >> c;
			if(a == 100 || b == 100 || c == 100){
				cout << "A" << endl;
			}else if(a + b >= 180){
				cout << "A" << endl;
			}else if(a + b + c >= 240){
				cout << "A" << endl;
			}else if(a + b + c >= 210){
				cout << "B" << endl;
			}else if(a + b + c >= 150 && (a >= 80 || b >= 80)){
				cout << "B" << endl;
			}else{
				cout << "C" << endl;
			}
		}
		
	}
	
	return 0;
}