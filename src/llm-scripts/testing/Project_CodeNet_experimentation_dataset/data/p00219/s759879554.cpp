#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

int main(void){
	int a,n;
	while(1){
		map<int,string> str;
		cin >> n;
		if(n==0)break;
		for(a=0;a<n;a++){
			int b;
			cin >> b;
			str[b].push_back('*');
		}
		for(a=0;a<=9;a++){
			if(str.size()>0)cout << str[a] << endl;
			else cout << "-" << endl;
		}
	}
	return 0;
}