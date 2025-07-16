#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int n;
	int ary[100][100];

while(1)
	{
		cin >> n;

		int sumx = 0;
		int sumy = 0;
		int sumxy = 0;

		if(n == 0)
		{
			break;
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
			{
				cin >> ary[i][j];
			}
		}

			for(int i = 0; i < n; i++){
				sumx = 0;
				for(int j = 0; j < n; j++)
				{
					sumx += ary[i][j];
					sumxy += ary[i][j];

					printf("%5d",ary[i][j] );
					//ary[i][j] << " ";//????????´???
				}
				printf("%5d", sumx);
				cout << endl;
			}

			for(int i = 0; i < n; i++){
				sumy = 0;
				for(int j = 0; j < n; j++)
			{
					sumy += ary[j][i];
				}
				printf("%5d", sumy);
			}
			printf("%5d\n", sumxy);
	}
}