#include <iostream>
#include <vector>
#include <set>
#include <cstring>	// require memset
//#include <fstream>	// require freopen

using namespace std;

const int N = 501;
bool t[N][N];

int main()
{
//	cut here before submit 
//	freopen ("testcase.party", "r", stdin );
	int n, m;

	while (cin >> n >> m && n && m ){
		int i,j;

		memset (t, false, sizeof (t ) );

		for (i = 0; i < m; ++i){
			int from, to;
			cin >> from >> to;
			t[from][to] = true;
			t[to][from] = true;
		} // end for
		set <int> res;

		for (i = 2; i <= n; ++i ){
			if (t[1][i] ){
				res.insert (i );
				for (j = 2; j <= n; ++j ){
					if (t[i][j]){
						res.insert (j );
					} // end if
				} // end for
			} // end if
		} // end for
		if (!res.empty() ){
			cout << res.size() << endl;
		}else{
			cout << '0' << endl;
		} // end if
	} // end loop
		
	return 0;
}