#include<iostream>
#include <stdio.h>
#include<string>
using namespace std;

int main(){
	int n;
	string line;
	scanf("%d ",&n);
	
	for(int x=0;x<n;x++){
		getline(cin,line);
		while (line.find("Hoshino") != string::npos) {
			line.replace(line.find("Hoshino"), 7, "Hoshina");
		}
		cout << line << endl;
    }
	return 0;
}