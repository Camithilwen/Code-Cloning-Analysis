#include<iostream>
#include<string>
using namespace std;

int main(){
	int n,pos;
	string s;
	while(cin>>n&&n){
		getline(cin,s);
		while(n--){
			getline(cin,s);
			while((pos=s.find("Hoshino",0))!=string::npos)
				s.replace(pos,7,"Hoshina");
			cout<<s<<endl;
		}
	}
	return 0;
}