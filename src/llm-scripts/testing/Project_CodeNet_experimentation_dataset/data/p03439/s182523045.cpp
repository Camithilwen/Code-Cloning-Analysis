#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;

	string f, e;
	cout << 0 << endl;
	cin >> f;
	if( f == "Vacant" ) return 0;
	cout << N - 1 << endl;
	cin >> e;
	if( e == "Vacant" ) return 0;
	int l = 0;
	int r = N - 1;
	while( r - l > 1 ) {
		int m = (l + r) / 2;
		string now;
		cout << m << endl;
		cin >> now;
		if( now == "Vacant" ) return 0;
		int s = r - m;
		if( s % 2 == 0 && now != e || s % 2 && now == e ) {
			l = m;
			f = now;
		}
		else {
			r = m;
			e = now;
		}
	}
}
