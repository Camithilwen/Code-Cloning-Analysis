#include <string>
#include <iostream>

using namespace std;

string reverse_seq(string str)
{
	string str_ = "";

	for(string::size_type i = 0; i < str.size(); i++)
	{
		str_ = str[i] + str_;
	}

	return str_;
}

int main()
{
	string str;

	cin>>str;
	
	cout << reverse_seq(str) << endl;
}