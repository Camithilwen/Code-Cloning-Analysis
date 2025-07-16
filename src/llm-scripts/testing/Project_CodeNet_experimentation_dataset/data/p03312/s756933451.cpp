#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum[1000000+5];
void Get(ll l,ll r,ll &first,ll &second)
{
    ll res =INT_MAX;
    ll left = l;
    ll right = r-1;
    while(left<=right)
    {
        ll mid = (left+right)>>1;
        ll a = sum[mid]-sum[l-1];
        ll b = sum[r]-sum[mid];
        if(abs(a-b)<res)
        {
            res = abs(a-b);
            first= a;
            second  = b;
        }
        if(a<=b)
        {
            left = mid+1;
        }
        else
        {
            right = mid-1;
        }
    }
}
int main()
{
    ll n;
    cin>>n;
    
    for(int i=1;i<=n;i++)
    {
    	int x;
    	cin>>x;
    	sum[i] =sum[i-1]+x;
    }
    // for(int i=0;i<=n;i++)
    // {
    // 	cout<<sum[i]<<" ";
    // }
    // cout<<endl;
    ll result =INT_MAX;
    for(ll i=2;i<=n-2;i++)
    {
        ll a;
        ll b;
        Get(1,i,a,b);
        ll c,d;
        Get(i+1,n,c,d);
	//	cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;       
        ll mx = max(max(a,b),max(c,d));
        ll mn = min(min(a,b),min(c,d));
        result = min(result,abs(mx-mn));
    }
    cout<<result<<endl;
    return 0;
}