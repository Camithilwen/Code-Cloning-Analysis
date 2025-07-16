//0017
#include <bits/stdc++.h>
using namespace std;

string str;

int find_str(){
	if(str.find("the",0) != string::npos)
		return 1;

	if(str.find("this",0) != string::npos)
		return 1;

	if(str.find("that",0) != string::npos)
		return 1;

	return 0;
}

int main(){
	int i,j;
	while(getline(cin,str)){
		for(i = 0;i < 26;i++){
			for(j = 0;j < str.size();j++){
			if('a'<=str[j]&&str[j]<='z'){
				if(25<(int)str[j]+1-'a'){
					str[j] = 'a';
				}else{
					str[j] = str[j] + 1;
				}
			}
			}
			if(find_str()){
				cout<<str<<endl;
				break;
			}
		}
	}
	return 0;
}