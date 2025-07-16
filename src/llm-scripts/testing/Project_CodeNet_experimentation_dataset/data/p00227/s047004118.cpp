#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main(int argc, char const* argv[])
{
	int n,m;
	int place[1000];

	while( cin >> n >> m && n != 0 ){
		for( int i = 0;i < 1000;i++ ) place[i] = 0;

		for( int i = 0;i < n;i++ ) cin >> place[i];
		sort( place, place + n, greater<int>() );

		for( int i = 1;i * m - 1 < n;i++ ) place[i * m - 1] = 0;
		
		int answer = 0;
		for( int i = 0;i < n;i++ ) answer += place[i];

		cout << answer << endl;
	}

	return 0;
}