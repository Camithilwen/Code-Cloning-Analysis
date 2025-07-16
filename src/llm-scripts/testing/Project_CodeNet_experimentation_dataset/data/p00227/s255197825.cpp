#include <iostream>
#include <vector>
#include <algorithm>
//#include <fstream>

using namespace std;

int main()
{
//	cut here before submit 
//	freopen ("testcase.thanksgiving", "r", stdin );
	int n, m;

	while (cin >> n >> m && n && m){
		vector <int> bp(n + 1);
		int i;

		bp[0] = 10001;
		for (i = 1; i <= n; ++i){
			cin >> bp[i];
		} // end while

		sort (bp.begin(), bp.end(), greater<int>() );

		int res = 0;

		for (i = 1; i <= n; ++i){
			if (i % m == 0){
				continue;
			} // end if
			res += bp[i];
		} // end for
		cout << res << endl;	

	} // end loop
		
	return 0;
}