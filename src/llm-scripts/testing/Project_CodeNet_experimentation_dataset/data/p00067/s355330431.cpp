#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <numeric>
#include <cmath>
#include <climits>
#include <limits>
#include <cfloat>
#include <fstream>
using namespace std;
#define SIZE 12
void init_v (vector <vector <bool> >& v )
{
	int size = v.size();
	int i, j;

	for (i = 0; i < size; ++i){
		v[i][0] = true;
		v[i][size - 1] = true;
	} // end for

	for (j = 0; j < size; ++j){
		v[0][j] = true;
		v[size - 1][j] = true;
	} // end for

}
	
void dfs (vector <vector <bool> >& v, vector <vector <int> > m, int row, int col )
{
	const int dir[][2] = { { 0, 1 }, { 1, 0 }, { 0, -1}, { -1, 0 } }; // ツ右ツ可コツ債カツ湘」
	int k;
	
	v[row][col] = true;

	for (k = 0; k < 4; ++k){
		if ( m[ row + dir[k][0] ][ col + dir[k][1] ] == 1 
		&&  !v[ row + dir[k][0] ][ col + dir[k][1] ] ){
			dfs (v, m, row + dir[k][0], col + dir[k][1] );
		} // end if
	} // end for
}

void disp_map (vector <vector <int> > m )
{
	int size = m.size();
	int len  = m[0].size();
	int i, j;

	for (i = 0; i < size; ++i){
		for (j = 0; j < len; ++j){
			cout << setw(2) << m[i][j] << ' ';
		} // end for
		cout << endl;
	} // end for
}

void disp_v (vector <vector <bool> > m )
{
	int size = m.size();
	int len  = m[0].size();
	int i, j;

	for (i = 0; i < size; ++i){
		for (j = 0; j < len; ++j){
			cout << setw(2) << m[i][j] << ' ';
		} // end for
		cout << endl;
	} // end for
}

int main()
{
//	cut here before submit 
//	freopen("testcase.island", "r", stdin);
	string str = "";
	int i = 1, j;
	vector <vector<int> > Map (SIZE + 2, vector <int> (SIZE + 2, 0 ) );

	while (getline (cin, str ) ){
		if (str.empty() ){
//			Map.clear();
			i = 1;
			continue;
		} // end if

		stringstream ss(str);
		ss >> str;
		for (j = 1; j <= SIZE; ++j){
			Map[i][j] = str[j-1] - '0';
		} // end for
		++i;

		if (i <= SIZE){
			continue;
		} // end if

//		cout << "i: " << i << endl;
//		disp_map (Map);

		int res = 0;
		vector <vector<bool> > visit (SIZE + 2, vector<bool> (SIZE + 2, false ) );
		init_v (visit );
		int row, col;

		for (row = 1; row < SIZE + 2; ++row){
			for (col = 1; col < SIZE + 2; ++col){
				if ( Map[row][col] == 1 && !visit[row][col]){
					++res;
					dfs (visit, Map, row , col );
//					disp_v (visit );
//					cout << endl;
				} // end if
				if (!visit[row][col]){
					visit[row][col] = true;
				} // end if
			} // end for
		} // end for
		cout << res << endl;
	} // end loop

//	cout << res << endl;	
		
	return 0;
}