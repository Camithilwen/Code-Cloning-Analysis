#include<bits/stdc++.h>
#define ll long long

const ll mod = 1000000007 ;

bool isInteger(double n)
{
	if(floor(n)==ceil(n))
		return true ;
	return false ;
}

using namespace std ;

int main()
{
	int k;
	cin>>k;
	string s;
	cin>>s;
	string s1="" ;
	if(s.length()<=k)
		cout<<s;
	else
	{
		for(int i=0 ;i<s.length() ;i++)
		{
			if(i<k)
				s1+=s[i];
		}
		s1+="...";
		cout<<s1;
	}

}
