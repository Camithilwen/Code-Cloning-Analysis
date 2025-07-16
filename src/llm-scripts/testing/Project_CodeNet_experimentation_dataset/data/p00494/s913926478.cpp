#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
int J = 0, O = 0, I = 0;
void res()
{
	J = 0;
	O = 0;
	I = 0;
}
int main()
{
	string a;
	cin >> a;
	int ans = 0;
	
	for (int i = 0; i < a.size(); i++)
	{
		switch (a[i])
		{
		case'J':
			if (O != 0 || I != 0)
			{
				res();
				J++;
			}
			else
			{
				J++;
			}
			break;
		case'O':
			if (J == 0||I!=0)
			{
				res();
				continue;
			}
			else
			{
				O++;
				if (O > J)
				{
					res();
				}
			}

			break;
		case'I':
			I++;
			if (O < I||J<I)
			{
				res();
			}
			if(I==O)ans = max(ans, I);
			break;
		}
	//	cout << ans << endl;

	}
	cout << ans << endl;

}