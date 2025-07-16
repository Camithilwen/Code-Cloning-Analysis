#include<iostream>
#include<string>
using namespace std;
int conv(char r)
{
	if(r=='I') return 1;
	if(r=='V') return 5;
	if(r=='X') return 10;
	if(r=='L') return 50;
	if(r=='C') return 100;
	if(r=='D') return 500;
	if(r=='M') return 1000;
	else return 0;
}

int main()
{
	string in;
	while(cin>>in)
	{
		int ans=0;
		for(int i = 1; i < in.size(); ++i)
		{
			int right=conv(in[i]);
			int left=conv(in[i-1]);
			if(!right||!left) continue;
			if(left<right)
			{
				ans+=right-left;
				in[i]=in[i-1]='0';
			}
		}
		for(int i = 0; i < in.size(); ++i)
		{
			ans+=conv(in[i]);
		}
		cout<<ans<<endl;
	}
  return 0;
}