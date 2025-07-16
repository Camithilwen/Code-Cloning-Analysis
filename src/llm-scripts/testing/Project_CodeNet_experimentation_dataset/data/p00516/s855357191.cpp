#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <functional>
#include <numeric>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
#include <set>

using namespace std;

#define ALL(co) co.begin(), co.end()

typedef long long LL;
typedef pair<int, int> P;
typedef pair<int, P> IP;
typedef pair<P, P> PP;
typedef vector<int> Array;
typedef vector<vector<int> > Array2;
typedef vector<int> LArray;

const int INF = 1 << 29;
const LL LINF = 1LL << 60;

int itiv;
inline int getInt() { return (cin >> itiv, itiv); }
void readAll(Array& vec, int n) { for (int i = 0; i < n; i++) cin >> vec[i]; }
inline bool between(int first, int last, int n) { return first <= n && n <= last; }
inline bool inRange(int begin, int end, int n) { return begin <= n && n < end; }
inline bool inRange(int size, int n) { return 0 <= n && n < size; }

int m, n;
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, -1, 0, 1 };
int dr[] = { 0, -1, 0, 1 }, dc[] = { -1, 0, 1, 0 };


int main(void)
{
	while(cin >> n >> m && n)
	{
		Array kyougi(n), sinsa(m);
		Array hyou(n);
		readAll(kyougi, n); readAll(sinsa, m);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if(kyougi[j] <= sinsa[i])
				{
					hyou[j]++;
					break;
				}
			}
		}
		cout << (max_element(ALL(hyou)) - hyou.begin()) + 1 << endl;
	}
	return 0;
}