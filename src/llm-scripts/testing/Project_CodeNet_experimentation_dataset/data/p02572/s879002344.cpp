#include<bits/stdc++.h> 
using namespace std;
long long s,ans;
int n,a[200003];
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    	cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++)
	{
        s=(s+a[i-1])%1000000007;
        ans=(ans+s*a[i])%1000000007;
    }
    cout<<ans<<endl;
    return 0;
}
