#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int friends[500];
	int n,m;
	pair<int, int> student[10000];
	int result[100];
	int I = 0;
	for (int i = 0;; i++)
	{
		cin >> n;
		cin >> m;
		if (m == 0 && n == 0)
		{
			break;
		}

		for (int a = 0; a < 500; a++)
		{
			friends[a] = 0;
			student[a].first = 0;
			student[a].second = 0;
		}

		for (int a = 0; a < m; a++)
		{
			cin >> student[a].first >> student[a].second;
			student[a].first--;
			student[a].second--;
		}

		sort(student, student + m);

		friends[0] = 1;

		for (int a = 0; a < m; a++)
		{
			if (student[a].first == 0)
			{
				for (int b = 0; b < m; b++)
				{
					if (student[b].first == student[a].second)
					{
						friends[student[b].second] = 1;
					}
					if (student[b].second == student[a].second)
					{
						friends[student[b].first] = 1;
					}
				}
				friends[student[a].second] = 1;
			}
		}

		result[i] = -1;
		for (int a = 0; a < n; a++)
		{
			if (friends[a] == 1)
			{
				result[i]++;
			}
		}
		I++;
	}

	for (int a = 0; a < I;a++)
	{
		cout << result[a] << endl;
	}

	return 0;
}