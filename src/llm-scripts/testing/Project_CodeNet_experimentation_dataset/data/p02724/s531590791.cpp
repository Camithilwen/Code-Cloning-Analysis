#include <bits/stdc++.h>
using namespace std;

double eps = 1e-9;
double pi = acos(-1);

#define fast_io ios_base::sync_with_stdio(false); cin.tie(0);
#define ll long long
#define en "\n"
#define ff first
#define ss second
#define sp(x) fixed << setprecision(x)
#define VECT(v)  vector<int>v
#define SCAN(v)  int temp; for(int i=0; i<n; i++) {cin>>temp; v.push_back(temp);}
#define PRINT(v) for(int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << en;
#define SORT(v)  sort(v.begin(), v.end());
#define RSORT(v) sort(v.begin(), v.end(), greater<>())
#define CASEP(v) cout<<"Case "<<tc<<": "<<v<<"\n"
#define DEBUG(v) cout << v << " "; cout << en;

int main(void)
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	fast_io

	int n, x;
	cin >> n;

	ll ans = 0;

	if(n >= 500)
	{
		x = n / 500;
		ans += 1000 * x;
		n = n - x * 500;
	}
	
	if(n >= 5)
	{
		x = n/5;
		ans += 5 * x;
	}

	cout << ans << en;

	return 0;
}