#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;


int main()
{
	string s;
	cin>>s;
	if(s.length()==2)cout<<s<<endl;
	else 
	{
		for(int i=2;i>=0;i--)cout<<s[i];
		cout<<endl;
	}
	return 0;
}