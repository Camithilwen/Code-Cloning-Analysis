#include <iostream>
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

using namespace std;

int main(){
	int n;
	string s;
	string alp = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string ans;
	while(1){
		cin >> n;
		if(n == 0) break;
		int k[n];
		for(int i = 0; i < n; i++){
			cin >> k[i];
		}
		cin >> s;
		for(int i = 0; i < s.length(); i++){
			int kn = i%ARRAY_LENGTH(k);
			int alpn = alp.find(s[i])-k[kn];
			if(alpn < 0) alpn += 52;
			else if(alpn > 52) alpn -=52;
			cout << alp[alpn];
		}
		cout << endl;
	}
}