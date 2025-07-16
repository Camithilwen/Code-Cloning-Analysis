#include <bits/stdc++.h>
using namespace std;

int main()
{
	string A;
	cin >> A;

	int N = A.size();
	vector<vector<long long>> v( N, vector<long long>( 26 ) );
	for( int i = 0; i < N; i++ ) {
		int j = A[N - 1 - i] - 'a';
		v[N - 1 - i][j]++;
	}
	for( int i = 0; i < N - 1; i++ ) {
		for( int j = 0; j < 26; j++ ) {
			v[N - 2 - i][j] += v[N - 1 - i][j];
		}
	}
	long long ans = 1;
	for( int i = 0; i < N; i++ ) {
		long long n = 0;
		int k = A[i] - 'a';
		for( int j = 0; j < 26; j++ ) {
			if( j == k ) continue;
			n += v[i][j];
		}
		ans += n;
	}

	cout << ans << endl;
}
