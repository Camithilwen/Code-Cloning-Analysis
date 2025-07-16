#include <iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;






int main()
{
	int N, Y;
	cin >> N >> Y;

	int set[3] = {-1,-1,-1};


	for (int i = 0; i <= N; i++)
	{
		for (int j = 0; i + j <= N; j++)
		{
			int k = N - i - j;
			int z = 10000 * i + 5000 * j + 1000 * k;
			if (z == Y)
			{
				set[0] = i;
				set[1] = j;
				set[2] = k;
				goto loopend;
			}
			else if(z > Y)
			{
				break;
			}
		}
	}

loopend:
	cout << set[0] << ' ' << set[1] << ' ' << set[2];

}

