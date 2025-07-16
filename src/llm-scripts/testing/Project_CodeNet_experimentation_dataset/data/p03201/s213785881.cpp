#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;

typedef pair <int, int> pii;
const int N = 3e3 + 5;
const long long INF = 1e18;
const int mod = 998244353;//786433;//998244353;
const double Pi = acos(-1);

 
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n;
int a[200005];
map <int, int> M;

int main()
{
	int t = 0;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		M[a[i]]++;
	}
	sort(a + 1, a + n + 1);
	for(int i = n; i >= 1; i--)
	{
		if(M[a[i]] == 0)
		{
			continue;
		}
		int temp = log2(a[i]);
		temp = 1 << (temp + 1);
		M[a[i]]--;
		if(M[temp - a[i]] > 0)
		{
			t++;
			M[temp - a[i]]--;
		}
	}
	cout << t;
}