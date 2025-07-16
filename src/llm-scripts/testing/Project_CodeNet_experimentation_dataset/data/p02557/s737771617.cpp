#include<bits/stdc++.h>
typedef  long long int ll;
typedef  long double ld;
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL) 
#define input(arr,n) for(ll i1=0;i1<n;i1++ )cin>>arr[i1]
#define mod 1000000007
#define F first
#define S second 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("O3")
//recursions\
#pragma comment(linker, "/stack:200000000")
//loops\
#pragma GCC optimize("unroll-loops")
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>//s.order_of_key(val) *s.find_by_order(ind)
using namespace std;

const int N = 1e6 + 5;
int main()
{
	sync;
	ll n;
	cin >> n;
	ll a[n], b[n], c[n];
	input(a, n);
	input(b, n);
	sort(b, b + n, greater<ll>());
	ll l = 1e9, r = -1;
	for(ll i = 0 ; i < n; i++)
	{
		if(a[i] == b[i])
		{
			l = min(l, i);
			r = max(r, i);
		}
	}
	if(r != -1)
	{
		for(ll i = 0; i < n; i++)
		{
			if(l > r)
				break;
			if(a[i] != a[r] && b[i] != a[r])
			{
				swap(b[l], b[i]);
				l++;
			}
		}
	}
	if(l <= r)
		cout << "No";
	else
	{
		cout << "Yes\n";
		for(ll i = 0; i < n; i++)
			cout << b[i] << " ";
	}
}