#include <cstring>
#include <iostream>

using namespace std;

#define MAX_N 512
#define MAX_M 10240

int N, M, A[MAX_M], B[MAX_M]; bool LIST[2][MAX_N];

int main()
{
	while (true)
	{
		memset(LIST, false, sizeof(LIST));

		cin >> N >> M;

		if (N == 0 && M == 0) { break; }

		for (int i = 1; i <= M; i++)
		{
			cin >> A[i] >> B[i];

			if (A[i] == 1)
			{
				LIST[0][B[i]] = true;
				LIST[1][B[i]] = true;
			}
		}

		for (int i = 1; i <= M; i++)
		{
			if (LIST[0][A[i]] == true)
			{
				LIST[1][B[i]] = true;
			}

			if (LIST[0][B[i]] == true)
			{
				LIST[1][A[i]] = true;
			}
		}

		int count = 0;

		for (int i = 2; i <= N; i++)
		{
			if (LIST[1][i] == true)
			{
				count++;
			}
		}

		cout << count << endl;
	}

	return 0;
}