#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int inf=0x3f3f3f3f;
long long a[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    long long d;
    cin>>d;
    a[0]=1;
    for(int i=1;i<=20;i++)
    	a[i]=a[i-1]*10;
    long long ans=0;
    for(int i=2;i<=20;i++)
    {
    	int k=i/2;
    	for(long long state=0;state<1<<k;state++)
    	{
    		long long cha,chan=d;
    		if(i%2==1)
    			cha=10;
    		else
    			cha=1;
    		for(int j=0;j<k;j++)
    		{
    			long long x=abs(chan)%10;
    			if(chan<0)
    			{
    				x=10-x;
    				x%=10;
				}
				if(state>>j&1)
				{
					long long sym=10-x;
					if(j==0)
						sym--;
					cha*=sym;
					chan+=x*a[i-2*j-1];
					chan-=x;
				}
				else
				{
					long long sym=x;
					if(j==0)
						sym--;
					if(sym<0)
					{
						cha=0;
						break;
					}
					cha*=sym;
					chan-=(10-x)*a[i-2*j-1];
					chan+=(10-x);
				}
				chan/=10;
			}
			if(chan==0)
				ans+=cha;
		}
	}
	cout<<ans<<endl;
	return 0;
}
