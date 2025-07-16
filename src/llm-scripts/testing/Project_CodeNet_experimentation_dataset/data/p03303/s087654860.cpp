#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	int n;
	cin>>str>>n;
	string adj;
	int at = 0;
	while(at < str.size())
	{
		adj.push_back(str[at]);
		at+=n;
	}
	cout<<adj<<endl;
	return 0;
}