#include <bits/stdc++.h>

#define F first
#define S second
#define pii pair<int, int>
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 10;

ll x[N], p[N];
ll ans;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, S; cin >> n >> S;
	int pos = -1;
	for (int i=0; i<n; i++)
	{
		cin >> x[i] >> p[i];
		if(x[i] < S) pos = i;
	}

	int st = 0, en = n - 1, dir = -1;
	while(true)
	{
		if(st > pos){ ans += x[en] - S; break ;}
		else if(en <= pos){ ans += S - x[st]; break; }
		if(p[st] >= p[en])
		{
			if(dir != 0) ans += x[en] - x[st];
			dir = 0;
			p[st] += p[en];
			en --;
		}else 
		{
			if(dir != 1) ans += x[en] - x[st];
			dir = 1;
			p[en] += p[st];
			st ++;
		}
	}
	cout << ans << endl;
}