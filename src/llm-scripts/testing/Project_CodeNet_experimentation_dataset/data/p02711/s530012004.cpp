#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	string N;
	cin >> N;
	int ja = 0;
	for (int i = 0; i < N.size(); i++) {
		if (N[i] == '7') {
			cout << "Yes" << endl;
			ja += 7;
			break;
		}
	}
	if (ja < 7) {
		cout << "No" << endl;
	}
	
}