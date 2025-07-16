#include <iostream>
#include<vector>
#include<string>
using namespace std;

int Roma(char a){
switch(a){
	case 'I':return 1;
	case 'V':return 5;
	case 'X':return 10;
	case 'L':return 50;
	case 'C':return 100;
	case 'D':return 500;
	case 'M':return 1000;
}
return 0;
}
int main() {
while(1){
	string a;
	cin>>a;
	if(cin.fail())break;
	int s=0;
	for(int b=0;b<a.length();b++){
		if(a.length()-1==b){
			s+=Roma(a[b]);
		}
		else{
			if(Roma(a[b])<Roma(a[b+1])){
				s+=Roma(a[b+1])-Roma(a[b]);
				b++;
			}
			else s+=Roma(a[b]);
		}
	}
	cout<<s<<endl;
}
}