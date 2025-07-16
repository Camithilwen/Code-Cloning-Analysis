#include <iostream>
#include <string>
using namespace std;

int a(char x){
	switch (x) {
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
	}
	return 0;
}
int main(void){
	string str;
	int ans=0;
	int p=0;
	while(cin>>str){
		ans=0;
		p=0;
		for(int i=str.length()-1;i>=0;i--){
			int now=a(str[i]);
			if(p>now)ans-=now;
			else ans+=now;
			p=now;
		}
		cout<<ans<<endl;
	}
	return 0;
}