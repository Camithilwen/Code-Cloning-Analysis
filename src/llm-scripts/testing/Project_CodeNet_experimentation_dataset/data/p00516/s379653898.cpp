



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	int n1 , n2;
	vector<int> val1 , val2 , ans;
	int input;

	cin >> n1 >> n2;

	for (int i = 0; i < n1; i++)
	{
		cin >> input;
		val1.push_back(input);
		ans.push_back(0);
	}
	for (int i = 0; i < n2; i++)
	{
		cin >> input;
		val2.push_back(input);
	}

	for (int i = 0; i < n2; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			if (val2[i] >= val1[j])
			{
				ans[j]++;
				break;
			}
		}
	}

	int Max = -100;
	int index = -1;

	for (int i = 0; i < ans.size(); i++)
	{
		if (ans[i] > Max)
		{
			Max = ans[i];
			index = i;
		}
	}

	cout << index + 1 << endl;

	return 0;
}