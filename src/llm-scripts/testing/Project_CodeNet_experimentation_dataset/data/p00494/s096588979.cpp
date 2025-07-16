#include <iostream>
#include <string>
using namespace std;

int k = 0, sum = 0, a[1000000];
string s;

int main() {
	cin >> s;
	
	for(int i = 0; i < s.size(); i++){
		sum++;
		if(s[i] != s[i + 1]){
			for(int j = i - sum + 1; j <= i; j++){
				a[j] = sum;
				sum--;
			}
			sum = 0;
		}
	}
	
	for(int i = 0; i < s.size(); i++){
		if(a[i] > k && s[i] == 'J'){
			if(a[i + a[i]] == a[i] && s[i + a[i]] == 'O' && a[i + a[i] * 2] >= a[i] && s[i + a[i] * 2] == 'I'){
				k = a[i];
			}
		}
	}
	
	cout << k << endl;
	
	return 0;
}