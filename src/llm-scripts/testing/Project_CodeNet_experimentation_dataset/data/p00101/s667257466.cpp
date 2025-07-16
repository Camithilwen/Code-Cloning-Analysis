#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	int i;
	while(cin >> n){
		i=n;
		string s[n];
		cin.ignore();
		while(n--){
			getline(cin,s[n]);
			int ix=0;
			while( ( ix =s[n].find("Hoshino") ) >=0 ){
				s[n].replace(ix,7,"Hoshina");
			}
		}
		while(i--){
			cout << s[i] << endl;
		}
	}
	return 0;
}