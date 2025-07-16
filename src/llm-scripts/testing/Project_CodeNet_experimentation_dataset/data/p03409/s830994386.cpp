#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false), cin.tie(0);
#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define endl '\n'

using namespace std;

main()
{
    fast;
    int n,a,b,i;
    cin>>n;
    vector<pair<pair<int,int>,int>> pts;
    for (i=0;i<n;i++)
    {
        cin>>a>>b;
        pts.pb(mp(mp(a,b),0));
    }
    for (i=0;i<n;i++)
    {
        cin>>a>>b;
        pts.pb(mp(mp(a,b),1));
    }
    sort(pts.begin(),pts.end());
    set<pair<int,int>> s;
    int ans=0,mark[2*n]={0};
    for (i=0;i<2*n;i++)
    {
        if (pts[i].ss==0)
            s.insert(mp(pts[i].ff.ss,i));
        else
        {
            int choose=-1;
            for (auto e: s)
            {
                if (e.ff<pts[i].ff.ss && mark[e.ss]==0)
                    choose=e.ss;
            }
            if (choose!=-1)
            {
                ans++;
                mark[i]=1;
                mark[choose]=1;
            }
        }
    }
    cout<<ans<<endl;
}
