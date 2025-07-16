#include<iostream>
#include<string>
using namespace std;
string s;
int main()
{
	getline(cin,s);
	s.erase(s.length()-8,s.length()-1);
	cout<<s<<endl;
	return 0;
}