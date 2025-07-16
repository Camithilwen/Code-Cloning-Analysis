#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

long long int nums[10000];

bool flags[10000];
int index[10000];

int main(){
	
	while(true){
		
		int n;
		
		cin >> n;
		
		if(n == 0){
			break;
		}
		
		for(int i = 0; i < 10000; i++){
			nums[i] = 0;
			flags[i] = true;
		}
		
		for(int i = 0; i < n; i++){
			long long int e, p, q;
			cin >> e >> p >> q;
			nums[e] += p * q;
			index[i] = e;
		}
		
		bool check = false;
		
		for(int i = 0; i < n; i++){
			if(nums[index[i]] >= 1000000 && flags[index[i]]){
				cout << index[i] << endl;
				check = true;
				flags[index[i]] = false;
			}
		}
		
		if(!check){
			cout << "NA" << endl;
		}
	}
	return 0;
}