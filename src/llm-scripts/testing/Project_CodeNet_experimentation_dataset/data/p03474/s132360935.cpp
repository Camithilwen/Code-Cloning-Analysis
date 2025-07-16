#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e3 + 7;
int ls1[Max], ls2[Max];
int n;


int main()
{
	int a, b;
	string str;
	cin >> a >> b;
	cin >> str;
	int f = 0;
	for (int i = 0; i <= str.size() - 1; i++)
	{
		if (i == a)
		{
			if (str[i] != '-')
			{
				f = 1;
				break;
			}
		}
		else
		{
			if (!(str[i] <= '9' && str[i] >= '0'))
			{
				f = 1;
				break;
			}
		}
	}
	if (f)cout << "No";
	else cout << "Yes";
}