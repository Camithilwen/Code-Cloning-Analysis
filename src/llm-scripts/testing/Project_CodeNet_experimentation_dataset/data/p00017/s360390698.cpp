#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <math.h>
#include <map>
#include <queue>
#include <string>
using namespace std;

char ch;
string text;

int main() {
    while(getline(cin,text)){
    	for(int i=0;i<26;i++){
    		for(int j=0;j<text.size();j++){
    			if(text[j]>='a'&&text[j]<='y')text[j]+=1;
    			else if(text[j]=='z')text[j]='a';
    		}
    		int p=text.find("the"),q=text.find("this"),r=text.find("that");
    		if(p!=string::npos||q!=string::npos||r!=string::npos){
    			cout<<text<<endl;
    			break;
    		}
    	}
    }
}