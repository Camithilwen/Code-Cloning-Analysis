#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <complex>
#include <ctime>
#include <cstdlib>

using namespace std;

inline int to_int(string s) {int v; istringstream sin(s); sin >> v; return v;}
template<class T> inline string to_str(T x) {ostringstream sout; sout << x; return sout.str();}

typedef long long ll;

const int N_prime = 15000;

class prime
{
		public:
			prime();
			vector<int> primeList;
			bool used[N_prime];
};

prime::prime()
{
	memset(used, true, sizeof(used));

	//一千万までの素数
	for(int i = 2; i < sqrt( N_prime ); i++)
	{
		if(used[i] == false)
		{
			continue;
		}

		for(int j = i*2; j < N_prime; j += i)
		{
			used[j] = false;
		}
	}

	for(int i = 2; i < N_prime; i++)
	{
		if(used[i] == true)
		{
			primeList.push_back(i);
		}
	}
}
int main()
{
	prime twin;
	int limit;
	while(cin >> limit, limit)
	{
		for(int i = 0; i < 10001; i++)
		{
			if(twin.primeList[i] > limit)
			{
				limit = i-1;
				break;
			}
			else if(twin.primeList[i] == limit)
			{
				limit = i;
				break;
			}
		}
		for(int i = limit; i > 0; i--)
		{
			if(twin.primeList[i-1] == twin.primeList[i]-2)
			{
				printf("%d %d\n",twin.primeList[i-1] ,twin.primeList[i]);
				break;
			}
		}
	}
}