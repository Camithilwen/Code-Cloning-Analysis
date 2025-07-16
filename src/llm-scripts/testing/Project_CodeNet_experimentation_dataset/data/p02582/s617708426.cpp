#include<iostream>
#include<algorithm>


using namespace std;

int main(){
	string s;
	cin>>s;
	if(s[0]=='R'){
		if(s[1]=='R'){
			if(s[2]=='R'){
				cout<<"3"<<endl;
			}
			else{
				cout<<"2"<<endl;
			}
		}
		else{
			cout<<"1"<<endl;
		}
	}
	else{
		if(s[1]=='R'){
			if(s[2]=='R'){
				cout<<"2"<<endl;
			}
			else{
				cout<<"1"<<endl;
			}
		}
		else{
			if(s[2]=='R') cout<<"1"<<endl;
			else cout<<"0"<<endl;
		}
	}
} 