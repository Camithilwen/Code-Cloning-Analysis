#include <iostream>
using namespace std;
typedef long long int LLI;
int main()
{
	int n, k, score = 1;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		if( score < k )
			score += score;
		else
			score += k;
	cout << score;
}