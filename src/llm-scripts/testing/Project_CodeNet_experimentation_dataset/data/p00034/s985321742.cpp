#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>	// require sort next_permutation count __gcd reverse etc.
#include <cstdlib>	// require abs exit atof atoi 
#include <cstdio>		// require scanf printf
#include <functional>
#include <numeric>	// require accumulate
#include <cmath>		// require fabs
#include <climits>
#include <limits>
#include <cfloat>
#include <iomanip>	// require setw
#include <sstream>	// require stringstream 
#include <cstring>	// require memset
#include <cctype>		// require tolower, toupper
#include <fstream>	// require freopen
#include <ctime>		// require srand
#define rep(i,n) for(int i=0;i<(n);i++)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main()
{
//	cut here before submit 
//	freopen ("testcase.RL", "r", stdin );
	string str = "";
	while (getline (cin, str ) ){
		if (str.empty() ) break;
		int n = str.length();
		rep (i, n ){
			if (str[i] == ',' ) str[i] = ' ';
		} // end rep
		vector<int> l (12, 0 ), sum (12, 0 );
		int v1, v2;
		stringstream ss (str );
		for (int i = 1; i <= 10; i++ ){
			ss >> l[i];
		} // end rep
		l[11] = 100000;
		ss >> v1 >> v2;
		for (int i = 1; i <= 11; i++ ){
			sum[i] = sum[i-1] + l[i];
		} // end for
/*
		cerr << "sum: " << endl;
		rep (i, 10+1 ){
			cerr << sum[i] << (i != 10 ? ' ' : '\n' );
		} // end rep
*/
		double t = (double)sum[10]/(double)(v1 + v2 );
//		cerr << "t: " << t << endl;
		double cl = (double)v1*t;
//		cerr << "cl: " << cl << endl;
		int res = 0;
		for (int i = 1; i <= 10; i++ ){
			if ((double)sum[i-1] < cl && cl <= (double)sum[i] ){
				res = i;
				break;
			} // end if
		} // end for
		printf ("%d\n", res );

	} // end loop

		
	return 0;
}