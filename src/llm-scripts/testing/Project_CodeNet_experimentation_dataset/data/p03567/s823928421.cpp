#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char n[10];
	cin>>n;
	for(int i=0;i<strlen(n);i++)
	{
		if(n[i]=='A'&&n[i+1]=='C')
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
}