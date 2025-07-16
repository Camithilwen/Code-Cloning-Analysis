
#include <bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define eps 1e-9
 
typedef long long ll;
 
using namespace std;
 
const ll inf = 1e18;
const ll mod = 1e9+7;
const int N = 2e5+5;
//int a[N];

int main()
 
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 	
 	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int d, t, s;

    cin >> d >> t >> s;

    if (((d+s-1)/s) > t) cout << "No";
    else cout << "Yes";

    return 0;
}