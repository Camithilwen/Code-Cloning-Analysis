#include <iostream>
#include<string>
using namespace std;

int main() {
	// your code goes here
	string s,t;
	cin>>s;
	cin>>t;
	for(int i = 0; t[i]!='\0'; i++)
	{
		cout<<t[i];
	}
	for(int i = 0; s[i]!='\0'; i++)
	{
		cout<<s[i];
	}
	return 0;
}