#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int waseda[10];
	int keo[10];
	for(int i = 0; i < 10; i++){
		cin >> waseda[i];
	}
	for(int i = 0; i < 10; i++){
		cin >> keo[i];
	}
	sort(waseda,waseda+10,greater<int>());
	sort(keo,keo+10,greater<int>());

	int sumW=0;
	int sumK=0;
	for(int i = 0; i < 3; i++){
		sumW += waseda[i];
		sumK += keo[i];
	}
	cout << sumW << " " << sumK << endl;

	return 0;
}