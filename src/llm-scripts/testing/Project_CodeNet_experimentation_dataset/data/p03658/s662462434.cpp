#include <bits/stdc++.h>
using namespace std;
#define ll long long int
//#define f(i,a,n) for(ll i=a;i<n;i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll isPrime(int n) 
{ 
	// Corner cases 
	if (n <= 1) 
		return 1; 
	if (n <= 3) 
		return 2; 

	// This is checked so that we can skip 
	// middle five numbers in below loop 
	if (n % 2 == 0 || n % 3 == 0) 
		return 1; 

	for (int i = 5; i * i <= n; i = i + 6) 
		if (n % i == 0 || n % (i + 2) == 0) 
			return 1; 

	return 2; 
} 

ll fact(ll n){ll res = 1;for (ll i = 2; i <= n; i++)res = res * i,res%=1000000007; 
    return res; } 
 
int main() 
{
    fast;
    ll t=1;
    //cin>>t;
    while(t--)
    {
        ll n,k,sum=0;
        cin>>n>>k;
        ll A[n];
        for(ll i=0;i<n;i++)
        {
            cin>>A[i];
        }
        sort(A,A+n);
        for(ll i=0;i<k;i++)
        {
            sum=sum+A[n-1-i];
        }
        cout<<sum;
    }
    return 0;
}
