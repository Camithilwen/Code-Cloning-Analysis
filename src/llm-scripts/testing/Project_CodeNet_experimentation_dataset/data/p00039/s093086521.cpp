using namespace std;
#include <iostream>
#include <string>
#include <set>
#include <functional>
#include <vector>
#include <algorithm>
#include <stdio.h>
int CtoI(char c){
	if(c=='I')return 1;
	else if(c=='V')return 5;
	else if(c=='X')return 10;
	else if(c=='L')return 50;
	else if(c=='C')return 100;
	else if(c=='D')return 500;
	else if(c=='M')return 1000;
}
int main()
{
	string s;
	while(getline(cin,s)){
		int ans=0;
		for(int i=1;i<(int)s.length();i++){
			int x=CtoI(s[i-1]);
			if(x<CtoI(s[i]))ans-=x;
			else ans+=x;
		}
		ans+=CtoI(s[(int)s.length()-1]);
		cout<<ans<<endl;
	}
    return 0;
}