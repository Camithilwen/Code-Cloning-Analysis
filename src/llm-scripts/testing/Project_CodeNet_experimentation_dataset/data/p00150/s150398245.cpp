#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <cstring>
#include <climits>

#define MAX 
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

using namespace std;

bool primearray[10000];

void erathos()
{
	int i;
	memset(primearray, 0, sizeof(primearray));

	REP( i, 2, 10000)
	{
		if( primearray[i] == 0 )
		{
			for( int j = i*2; j < 10000; j+=i)
			{
				primearray[j] = 1;
			}
		}
	}

	return;
}

int main()
{
	int in;

	erathos();

	while( cin >> in, in)
	{
		for( int i = in ; i > 0; i--)
		{
			if( primearray[i] == 0 && primearray[i-2] == 0 )
			{
				cout << i-2 << " " << i << endl;
				break;
			}
		}
	}

	return 0;

}