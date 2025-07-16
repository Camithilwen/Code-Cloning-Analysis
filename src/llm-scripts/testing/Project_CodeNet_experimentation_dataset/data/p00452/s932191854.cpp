#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;
typedef long long int int64;

vector<int64> P,Q;
int64 N,M,T;

int main(void)
{
	while(true)
	{
		N = 0;
		M = 0;
		P.clear();
		Q.clear();
		P.shrink_to_fit();
		Q.shrink_to_fit();
		cin >> N >> M;
		if(N == 0 && M == 0)
		{
			exit(0);
		}
		for(int i = 0;i < N;i++)
		{
			cin >> T;
			P.push_back(T);
		}
		P.push_back(0);
		for(auto itr = P.begin();itr < P.end();itr++)
		{
			for(auto itr2 = P.begin();itr2 < P.end();itr2++)
			{
				Q.push_back(*itr + *itr2);
			}
		}
		Q.push_back(LLONG_MAX / 2);
		Q.push_back(LLONG_MIN / 2);
		sort(Q.begin(),Q.end());
		int64 ms = 0;
		for(auto itr = Q.begin();itr < Q.end()+1;itr++)
		{
			ms = max(ms,*itr + *(lower_bound(Q.begin(),Q.end() - 1,M-*itr+1) - 1));
		}
		cout << ms << endl;
	}
}