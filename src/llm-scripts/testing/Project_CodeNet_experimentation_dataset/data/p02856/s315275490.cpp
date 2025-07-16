#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	vector<int> d(10),e(10);
	for(int i = 1;i<10;i++)
	{
		int now = i*2;
		int num = 2;
		int cnt = 1;
		while(now != i)
		{
			if(now>9)
			{
				now = now%10+now/10;
				cnt++;
				if(now==i)break;
			}
			now += i;
			num++;
			cnt++;
			if(now==i)break;
			if(now>9)
			{
				now = now%10+now/10;
				cnt++;
				
			}
		}
		//cout<<i << ' ' << num << ' ' << cnt<<endl;
		d[i]= num;
		e[i]= cnt;
		d[i]--;
	}
	d[0] = 1;
	e[0]=1;
	int n;
	cin >> n;
	ll ans = 0;
	int now = 0;
	map<ll,ll> mp;
	for(int i = 0;i<n;i++)
	{
		ll x,y;
		cin >> x >> y;
		mp[x] += y;
	}
	for(int i = 0;i<10;i++)
	{
		if(mp[i]>0)
		{
			mp[i]--;
			ans += mp[i]/d[i]*e[i];
			//cout << mp[i]<<endl;
			//cout<< "ans" << ans << endl;
			//cout << d[i] <<';'<< e[i]<<endl;;
			mp[i]%=d[i];
			mp[i]++;
			for(int j = 0;j<mp[i];j++)
			{
				now += i;
				ans++;
				if(now>9)
				{
					now = now/10+now%10;
					ans++;
				}
			}
		}
	}
	cout << ans -1<< endl;

}
