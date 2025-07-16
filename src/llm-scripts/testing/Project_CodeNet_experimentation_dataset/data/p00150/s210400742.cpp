#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	bool no[10001] = {true,true};
	for(int i = 4;i <= 10000;i += 2) no[i] = true;
	for(int i = 3;i * i <= 10000;i += 2){
		for(int j = i * 2;j <= 10000;j += i) no[j] = true;
	}
	vector<int> twin;
	for(int i = 2;i <= 10000;i++){
		if(!no[i] && !no[i - 2]) twin.push_back(i);
	}
	while(cin >> n,n){
		int pos = upper_bound(twin.begin(),twin.end(),n) - twin.begin() - 1;
		cout << twin[pos] - 2 << " " << twin[pos] << endl; 
	}
	return 0;
}