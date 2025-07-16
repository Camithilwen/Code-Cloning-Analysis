/*DavitMarg*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <iomanip>
#include <bitset>
#include <stack>
#include <cassert>
#include <iterator>
#include <fstream>
#define mod 1000000007ll
#define LL long long
#define LD long double
#define MP make_pair
#define PB push_back
#define all(v) v.begin(), v.end()
using namespace std;

const int N = 1003;

int n, cnt = 0, d;
char a[N][N];

char get(int d)
{
	return (char)(d % 26 + 'a');
}

void addHor(int y, int x)
{
	a[y][x] = get(d);
	a[y][x + 1] = get(d);
	d++;
}


void addVer(int y, int x)
{
	a[y][x] = get(d);
	a[y + 1][x] = get(d);
	d++;
}


void add7(int y, int x)
{
	addVer(y, x);
	addHor(y, x + 1);
	addHor(y, x + 3);

	addHor(y + 1, x + 2);
	addHor(y + 1, x + 5);

	addVer(y + 2, x + 2);
	addVer(y + 2, x + 4);
	addHor(y + 2, x + 5);

	addVer(y + 3,x);

	addVer(y + 4, x + 1);
	addVer(y + 4, x + 6);

	addVer(y + 5, x + 3);

	addHor(y + 6, x);
	addHor(y + 6, x+4);
}

void add6(int y, int x)
{
	addHor(y, x);
	addVer(y, x + 2);
	addHor(y+2, x+1);
	addVer(y+1, x);


	addVer(y+3, x);
	addHor(y+3 + 2, x + 1);


	addVer(y, x + 3);
	addHor(y + 2, x + 3 + 1);


	addHor(y + 3, x+3);
	addVer(y + 3, x +3+ 2);
	addHor(y + 3 + 2, x+3 + 1);
	addVer(y + 3 + 1, x+3);

}


void add5(int y, int x)
{

	addHor(y, x);
	addHor(y, x + 2);

	addHor(y + 4, x + 1);
	addHor(y + 4, x + 3);

	addVer(y + 1, x);
	addVer(y + 3, x);

	addVer(y, x+4);
	addVer(y + 2, x+4);

	addVer(y+1,x+1);
	addHor(y + 3, x + 2);
}

void add3(int y, int x)
{
	addHor(y,x);
	addVer(y+1, x);
	addVer(y, x+2);
	addHor(y+2, x+1);
}

void solve(int l, int r)
{
	if (r - l + 1 <= 2)
		return;


	if ((r - l + 1) == 7)
	{
		add7(l, l);
		return;
	}

	if ((r - l + 1) == 6)
	{
		add6(l, l);
		return;
	}

	if ((r - l + 1) == 5)
	{
		add5(l,l);
		return;
	}
	

	if ((r - l + 1) == 3)
	{
		add3(l, l);
		return;
	}

	if ((r - l + 1) == 6)
	{
		add6(l, l);
		return;
	}

	a[l][l] = get(d);
	a[l][l + 1] = get(d);
	d++;
	a[l][r] = get(d);
	a[l + 1][r] = get(d);
	d++;
	a[r][r] = get(d);
	a[r][r - 1] = get(d);
	d++;
	a[r][l] = get(d);
	a[r - 1][l] = get(d);
	d++;

	a[l + 1][l] = get(d);
	a[l + 1][l + 1] = get(d);
	d++;
	a[l][r - 1] = get(d);
	a[l + 1][r - 1] = get(d);
	d++;
	a[r - 1][r] = get(d);
	a[r - 1][r - 1] = get(d);
	d++;
	a[r][l + 1] = get(d);
	a[r - 1][l + 1] = get(d);
	d++;

	l += 2;
	r -= 2;
	solve(l, r);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = '.';

	if (n > 2)
		solve(1, n);
	else
	{
		cout << -1 << endl;
		return 0;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << a[i][j];
		cout << endl;
	}
	return 0;
}

/*


100 20 81



*/