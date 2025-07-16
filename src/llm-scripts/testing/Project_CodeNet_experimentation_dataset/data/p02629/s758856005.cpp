#include <bits/stdc++.h>
using namespace std;

/*
提出前に確認!
- setとmultisetを間違えない
*/

/*
26進数で考えればいい
*/

void	solve(long long num)
{
	if (num == 0) return ;
	num--;
	solve(num / 26);
	cout << (char)(num % 26 + 'a');
}

int		main(void)
{
	long long n;
	cin >> n;
	solve(n);
	cout << endl;
	return (0);
}
