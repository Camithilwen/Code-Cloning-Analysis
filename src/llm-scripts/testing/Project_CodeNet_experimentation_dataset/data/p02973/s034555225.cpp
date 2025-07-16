#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010;

int n;
int q[N];

int main()
{
	scanf("%d", &n);
	
	int cnt = 0;
	for (int i = 1; i <= n; i ++ )
	{
		int x;
		scanf("%d", &x);
		
		int l = 1, r = cnt;
		while (l < r)
		{
			int mid = l + r >> 1;
			if (q[mid] < x) r = mid;
			else l = mid + 1;
		}
		
		if (!cnt || q[cnt] >= x) q[ ++ cnt] = x;
		else q[r] = x;
	}
	
	printf("%d\n", cnt);
    return 0;
}