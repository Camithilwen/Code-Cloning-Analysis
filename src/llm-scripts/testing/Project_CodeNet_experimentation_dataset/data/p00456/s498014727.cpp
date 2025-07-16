#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

int main(){

	int w[10], k[10];
	
	for(int i=0; i<2; i++){
		for(int j=0; j<10; j++){
			if(i == 0) cin >> w[j];
			else cin >> k[j];
		}
	}
	
	sort(w, w+10, greater<int>());
	sort(k, k+10, greater<int>());
	
	cout << w[0] + w[1] + w[2] << " " << k[0] + k[1] + k[2] << endl;
	
	return 0;

}