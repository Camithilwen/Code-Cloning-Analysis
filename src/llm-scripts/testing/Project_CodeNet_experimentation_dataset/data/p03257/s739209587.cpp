#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <stack>
#include <queue>
#include <set>
#include <list>
#include <bitset>
#include <array>

using namespace std;

#define fi first	
#define se second
#define long long long
typedef pair<int,int> ii;

vector<long> vec;
bool prime(int x)
{
	for(int i = 2; i <= sqrt(x); i++)
	{
		if(x%i == 0)
			return 0;
	}
	return 1;
}
long MAXN = 500;
long A[503][503];
long gcd(long a, long b) {return (b)? gcd(b,a%b) : a;}
long lcm(long a, long b) 
{
	if(a == b && b == 0) return 0;
	else if(a == 0) return b;
	else if(b == 0) return a;
	else return a/gcd(a,b)*b;
}

int main()
{
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("input.in", "r", stdin);

	for(int i = 2; i <= 10000; i++)
		if(prime(i))
			vec.push_back(i);

	int n; scanf("%d", &n);

	int idx = 0;
	for(int i = 1; i <= MAXN; i+=2)
	{
		int x = 1, y = i;
		while(y <= MAXN)
			A[x++][y++] = vec[idx];
		idx++;
	}
	for(int i = 3; i <= MAXN; i+=2)
	{
		int x = i, y = 1;
		while(x <= MAXN)
			A[x++][y++] = vec[idx];
		idx++;
	}
	for(int i = 1; i <= MAXN; i+=2)
	{
		int x = 1, y = i;
		while(y >= 1 && x <= MAXN)
			A[x++][y--] *= vec[idx];
		idx++;
	}
	for(int i = MAXN; i >= 2; i-=2)
	{
		int x = i, y = MAXN;
		while(y >= 1 && x <= MAXN)
			A[x++][y--] *= vec[idx];
		idx++;
	}

	long mx = 0;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(A[i][j] == 0) A[i][j] = lcm(lcm(A[i-1][j],A[i][j-1]),lcm(A[i+1][j],A[i][j+1]))+1;
			// mxnax(A[i][j],mx);
			printf("%lld", A[i][j]);
			if(j < n) printf(" ");
		}
		printf("\n");
	}
	// printf("%lld\n", mx);
}









