#include <iostream>
#include <string>

using namespace std;

int main(){
	string str;
	//string reverse="";
	cin>>str;
	for (int i=str.length()-1; i>-1; i--){
		cout<<str.at(i);
	}
	cout<<endl;
	//cout<<reverse<<endl;
	return 0;
}