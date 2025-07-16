#include<iostream>
using namespace std;

int main()
{
	int N;
	int M;
	int x[20];
	int y[20];
	char d;
	int l;

	while (cin >> N && N != 0)
	{
		int flag[21][21] = {};
		int initX = 10;
		int initY = 10;
		int cnt = 0;

		for (int i = 0; i < N; i++)
		{
			cin >> x[i];
			cin >> y[i];
			flag[y[i]][x[i]] = 1;
		}

		cin >> M;

		for (int i = 0; i < M; i++)
		{
			cin >> d;
			cin >> l;
			int dx = 0;
			int dy = 0;

			for (int k = 0; k <= l; k++)
			{
				if (d == 'S' || d == 'W')
				{
					if (d == 'S')
					{
						for (int j = 0; j < N; j++)
						{
							if (x[j] == initX && y[j] == initY - k && flag[y[j]][x[j]] == 1)
							{
								cnt++;
								flag[y[j]][x[j]] = 0;
							}
						}
					}
					else
					{
						for (int j = 0; j < N; j++)
						{
							if (x[j] == initX - k && y[j] == initY && flag[y[j]][x[j]] == 1)
							{
								cnt++;
								flag[y[j]][x[j]] = 0;
							}
						}
					}
				}
				else
				{
					if (d == 'N')
					{
						for (int j = 0; j < N; j++)
						{
							if (x[j] == initX && y[j] == initY + k && flag[y[j]][x[j]] == 1)
							{
								cnt++;
								flag[y[j]][x[j]] = 0;
							}
						}
					}
					else
					{
						for (int j = 0; j < N; j++)
						{
							if (x[j] == initX + k && y[j] == initY && flag[y[j]][x[j]] == 1)
							{
								cnt++;
								flag[y[j]][x[j]] = 0;
							}
						}
					}
				}
			}
			if (d == 'S')
			{
				dy = -l;
			}
			else if (d == 'N')
			{
				dy = l;
			}
			else if (d == 'W')
			{
				dx = -l;
			}
			else
			{
				dx = l;
			}

			initX += dx;
			initY += dy;
		}
		if (cnt == N)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}

	}
	return 0;
}