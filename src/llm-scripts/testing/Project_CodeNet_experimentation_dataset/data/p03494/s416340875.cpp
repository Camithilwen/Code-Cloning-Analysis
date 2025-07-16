#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int num[N];
	int i = 0, count = 0;
	while (i < N)
		cin >> num[i++];
	int flag=0;
	while (true)
	{
		i = 0;
		while (i < N)
		{
			if (num[i] % 2 != 0)
				flag = 1;
			num[i] /= 2;
			i++;
		}
		if (flag == 1)
			break;
		count++;
	}
	cout << count << endl;
}