#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	int n;
	while (cin>>n)
	{
		if (n == 0)break;
		int data[11][11] = { 0 };

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> data[i][j];
			}
		}

		for (int i = 0; i < n; i++)          //??????????¨????
		{
			for (int j = 0; j < n; j++)
			{
				data[i][n] += data[i][j];
			}
		}

		for (int i = 0; i < n; i++)           //??????????¨????
		{
			for (int j = 0; j < n+1; j++)     //n??????????????????
			{
				data[n][j] += data[i][j];
			}
		}


		for (int i = 0; i < n+1; i++)
		{
			for (int j = 0; j < n+1; j++)
			{
				cout.width(5);
				cout << data[i][j];
			}
			cout << endl;
		}
	}


	return 0;
}