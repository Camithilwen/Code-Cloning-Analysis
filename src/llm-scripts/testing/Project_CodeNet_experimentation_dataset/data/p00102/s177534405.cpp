#include <iostream>
#include <iomanip>
#include<vector>
using namespace std;
int main()
{
	while(1)
	{
		int N;
		cin >> N;
		if(N == 0)
		{
			return 0;
		}

		vector<vector<int>> map;

		//??????????????????
		for(int i = 0; i < N+1; i++)
		{
			vector<int> column;
			for(int j = 0; j < N + 1; j++)
			{
				if(i == N)
				{
					column.push_back(0);
				}
				else if(j != N)
				{
					int value;
					cin >> value;
					column.push_back(value);
				}
				else
				{
					column.push_back(0);
				}

			}  
			map.push_back(column);
		}
		//?????????????¨????
		int totalSum = 0;
		//????????????????¨????
		for(int i = 0; i < N; i++)
		{
			int sum = 0;
			for(int j = 0; j < N; j++)
			{
				sum += map[i][j];
			}
			map[i][N] = sum;
		}
		//????????????????¨????
		for(int i = 0; i < N; i++)
		{
			int sum = 0;
			for(int j = 0; j < N; j++)
			{
				sum += map[j][i];
			}
			map[N][i] = sum;
			totalSum += sum;
		}
		//????????????????¨???????????????£??\
		map[N][N] = totalSum;

		for(int i = 0; i < N + 1; i++)
		{
			for(int j = 0; j < N + 1; j++)
			{
				cout << setw(5) << right << map[i][j];
			}
			cout << endl;
		}
	}

}