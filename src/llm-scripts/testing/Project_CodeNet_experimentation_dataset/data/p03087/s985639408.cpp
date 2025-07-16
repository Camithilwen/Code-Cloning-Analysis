/* 十 聖イシドールスよ、迷えるプログラマを導き給え！ 十 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>
#include <deque>

#define rep(i, n) for(int i = 0; i < n; i++)

//const long long INF = 1LL << 60;
const int INF = 1e9;
using ll = long long;

int main()
{
	int N, Q;
	std::cin >> N >> Q;
	std::vector<int> ACGT(N, 0);	// AGCT[i]文字目までに何個現れたか
	std::string S;
	std::cin >> S;

	// 前処理...ACの数を数えておく 
	char pre = S[0];
	for( int i = 1; i < N; i++ )
	{
		char now = S[i];
		//printf( "%c:%c", pre, now );
		ACGT[i] = ACGT[i-1];
		if( pre == 'A' )
		{
			if( now == 'C')
			{
				//printf("now!");
				ACGT[i] = ACGT[i-1] + 1;
			}
		}
		//printf("\n");
		pre = now;
	}

//	printf("===\n");
//	rep( i, N )
//	{
//		printf( "%d\n", ACGT[i]);
//	}
//	printf("===\n");
	
	// 問題をとく 
	for( int i = 0; i < Q; i++ )
	{
		int l, r;
		std::cin >> l >> r;
		l--; r--;

		int ans = ACGT[r] - ACGT[l];

		if( ( S[l] == 'A' ) && ( S[r] == 'C' ) )
		{
			//ans++;
		}	

		std::cout << ans << std::endl;
	}

	return 0;
}
