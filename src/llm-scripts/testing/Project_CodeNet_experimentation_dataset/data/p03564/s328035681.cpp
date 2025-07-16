#include <bits/stdc++.h>
using namespace std;
 
int main(void)
{
	int N, K, i, min;
	cin >> N >> K;
	min = 1;
	for (i = 0; i < N; ++i)
    {
      if (min * 2 < min + K)
      {
        min *= 2;
      }
      else
      {
        min += K;
      }
    }
	cout << min << endl;
	return (0);
}