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

int main()
{
	int L[16];
	int sum;
	int v1, v2;
	double crush;
	int ans;
	while(scanf("%d",&L[0]) != EOF)
	{
		sum = L[0];
		for(int i = 1; i < 10; i++)
		{
			scanf(",%d",&L[i]);
			sum += L[i];
		}
		scanf(",%d,%d", &v1, &v2);

		crush = sum * (v1 * 1.0/(v1+v2) );

		for(int i = 0; i < 10; i++)
		{
			crush -= L[i];
			if(crush <= 0)
			{
				ans = i+1;
				break;
			}
		}
		cout << ans << endl;
	} 
}