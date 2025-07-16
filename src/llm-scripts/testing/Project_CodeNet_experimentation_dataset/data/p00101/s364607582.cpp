#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(){
	string s;
	int n;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++){
		getline(cin,s);
		while (1){
			int index = s.find("Hoshino");
			if (index == -1) break;
			s.replace(index,7,"Hoshina");
		}
		cout << s << endl;
	}
	return 0;
}