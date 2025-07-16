#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s,d[10];
	cin>>s;
	int i,j,a,b;
	a=s.size();
	int c[a-2];
	for(i=0;i<a-2;i++)
	{
		for(j=i;j<i+3;j++)
		{
			d[i]=d[i]+s[j];
		}
		c[i]=abs(753-stoi(d[i]));
	}
	sort(c,c+(a-2));
	cout<<c[0]<<endl;
	
}