#include<iostream>
#include<string>

using namespace std;

int conv(char str)
{
	if(str=='I')
	{
		return 1;
	}
	else if(str=='V')
	{
		return 5;
	}
	else if(str=='X')
	{
		return 10;
	}
	else if(str=='L')
	{
		return 50;
	}
	else if(str=='C')
	{
		return 100;
	}
	else if(str=='D')
	{
		return 500;
	}
	else if(str=='M')
	{
		return 1000;
	}
}

int conv(string str)
{
	int ans=0;
	for(int i=0;i<str.length();i++)
	{
		if(i==str.length()-1)
		{
			ans+=conv(str[i]);
		}
		else if(conv(str[i])<conv(str[i+1]))
		{
			ans-=conv(str[i]);
		}
		else ans+=conv(str[i]);
	}
	return ans;
}

int main(void)
{
	string str;
	while(cin>>str)
	{
		cout<<conv(str)<<endl;
	}
}