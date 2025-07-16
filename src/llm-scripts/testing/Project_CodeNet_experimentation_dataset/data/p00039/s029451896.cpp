#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <stdio.h>
using namespace std;
int main(){
	string str;
	while(cin>>str){
		int num=0;
		vector<int> roman;
		for(int i=0;i<str.length();i++){
			if(str[i]=='I'){
				roman.push_back(1);
			}else if(str[i]=='V'){
				roman.push_back(5);
			}else if(str[i]=='X'){
				roman.push_back(10);
			}else if(str[i]=='L'){
				roman.push_back(50);
			}else if(str[i]=='C'){
				roman.push_back(100);
			}else if(str[i]=='D'){
				roman.push_back(500);
			}else if(str[i]=='M'){
				roman.push_back(1000);
			}
		}
		for(int i=0;i<roman.size();i++){
			if(i==roman.size()-1){
				num += roman[roman.size()-1];
			}else{
				if(roman[i]<roman[i+1]){
					num += roman[i+1]-roman[i];
					i++;
				}else{
					num += roman[i];
				}
			}
		}
		cout<<num<<endl;
	}
	return 0;
}