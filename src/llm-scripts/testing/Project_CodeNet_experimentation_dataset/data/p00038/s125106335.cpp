#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n; char c; string s;
	while(cin >> n)
	{
		int cd[13]={0},pr[5]={0};

		cd[n-1]++;
		for(int i=0; i<4; i++)
		{
			cin >> c >> n;
			cd[n-1]++;
		}

		for(int i=0; i<13; i++)
		{
			pr[cd[i]]++;
		}

		bool st=false;
		for(int i=0; i<10; i++)
		{
			int sm=0;
			for(int j=0; j<5; j++) sm+=(cd[(i+j)%13]?1:0);
			if(sm==5) st=true;
		}

		                      s="null";
		     if(pr[4])        s="four card";
		else if(pr[3]&&pr[2]) s="full house";
		else if(st)           s="straight";
		else if(pr[3])        s="three card";
		else if(pr[2]==2)     s="two pair";
		else if(pr[2])        s="one pair";

		cout << s << endl;
	}
}