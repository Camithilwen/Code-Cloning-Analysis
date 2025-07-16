#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mxn=2e5+3,du=1e9+7;
int m,n;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>m>>n;
	map<int,int> mp;
	multiset<int> s;
	for (int i=1;i<=n;i++) mp[i]=i,s.insert(0);
	for (int i=1;i<=m;i++)
    {
        int l,r;
        cin>>l>>r;
        auto it=mp.lower_bound(l);
        int mx=0;
        while(it!=mp.end()&&it->first<=r)
        {
            mx=max(mx,it->second);
            int dis=(it->first)-(it->second);
            s.erase(s.find(dis));
            mp.erase(it++);
        }
        if (mx!=0&&r<n&&mp.find(r+1)==mp.end())
        {
            mp[r+1]=mx;
            s.insert(r+1-mx);
        }
       // cout<<"DM";
        if (s.size()) cout<<(*s.begin())+i<<"\n";
        else cout<<-1<<"\n";
    }
	return 0;
}
