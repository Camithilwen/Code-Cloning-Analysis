#include <iostream>
#include <algorithm>
#include <cstring>

#define rep(X, Y) for( int X = 0; X < Y; ++X )

int n, m;
int N[1001], M[1001];
int cnt[1001];

int main(){
	memset( cnt, 0, sizeof(cnt) );

	std::cin >> n >> m;

	rep( i, n ) std::cin >> N[i];

	rep( i, m ) std::cin >> M[i];

	rep( i, m ) rep( l, n ) if( N[l] <= M[i] ){
		cnt[l]++;
		break;
	}

	std::cout << std::max_element( cnt, cnt + n ) - cnt + 1 << std::endl;

	return 0;
}