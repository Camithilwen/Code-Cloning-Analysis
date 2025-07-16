#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int main(){
	int sum;
	string st;
	map <char,int> code;
	code['I']=1;
	code['V']=5;
	code['X']=10;
	code['L']=50;
	code['C']=100;
	code['D']=500;
	code['M']=1000;
	
	while(cin>>st){
		sum=0;
		for(int i=0;i<st.size()-1;i++){
			if(code[st[i]]<code[st[i+1]])
			sum-=code[st[i]];
			else
			sum+=code[st[i]];
		}
		printf("%d\n",sum+code[st[st.size()-1]]);
	}
}
