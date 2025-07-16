#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#define ll long long
using namespace std;
ll _11[18];
int main()
{
	ll d;
	scanf("%lld",&d);
	if(d%9){puts("0");return 0;}
	d/=9;
	ll ans=0;
	for(int i=1;i<=17;i++) _11[i]=_11[i-1]*10+1;
	ll len=1;
	for(int i=1;i<=17;i++)
	{
		ll res=1,del=d,L=len,R=1,b=_11[i];
		for(int j=0;j<=(i>>1);j++)
		{
			res*=10-abs(del%(R*10)/R)-(!j);
            del-=b*(del%(R*10)/R);
            b-=L+R;
            L/=10;
            R*=10;
        }
        if(!del) ans+=res;
        len*=10;
	}
	printf("%lld",ans);
	return 0;
}
