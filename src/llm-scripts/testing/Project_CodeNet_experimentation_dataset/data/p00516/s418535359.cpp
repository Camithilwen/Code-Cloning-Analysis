#include <iostream>
#include <vector>

using namespace std;

void solve()
{
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	vector<int> B(M);
	for(int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	for(int i = 0; i < M; ++i)
	{
		cin >> B[i];
	}
	vector<int> point(N);
	int max = 0;
	for(int i = 0; i < M; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			if(B[i] >= A[j])
			{
				++point[j];
				if(max < point[j])
				{
					max = point[j];
				}
				break;
			}
		}
	}
	for(int i = 0; i < M; ++i)
	{
		if(max == point[i])
		{
			cout << i + 1 << endl;
		}
	}
}

int main()
{
	solve();
	return(0);
}