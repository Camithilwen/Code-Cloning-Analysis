/*input
4
141421356 17320508 22360679 244949
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int M=1e9+7;
int n, sq=0, s=0;
int a[200005];

signed main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; ++i){
		cin>>a[i];
	}
	for(int i=2; i<=n; ++i){
		s += a[i]*(a[i-1])%M;
		s %= M;
		(a[i] += a[i-1]) %= M;;
	}
	cout<<s;
	return 0;	
}