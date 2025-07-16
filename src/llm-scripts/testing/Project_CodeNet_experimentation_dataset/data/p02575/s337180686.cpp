#include<bits/stdc++.h>
using namespace std;
#define Nitroboost  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int 
const int mod=1e9+7;
const int N=1e6+5;



int main()
    {
        Nitroboost;
        #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        #endif

        int n,m;
        cin>>n>>m;
        map<int,int>mp;
        for(int i=1;i<=m;i++)
            mp[i]=i;

        multiset<int>v;
        for(int i=1;i<=m;i++)
            v.insert(0);

        for(int i=1;i<=n;i++)
        {
            int l,r;
            cin>>l>>r;
            r++;
            auto it=mp.lower_bound(l);
            int t=-1;
            while(it!=mp.end() && it->first<=r)
            {
                t=max(t,it->second);
                v.erase(v.find(it->first-it->second));
                mp.erase(it++);
            }
            if(t!=-1 && r<=m)
            {
                v.insert(r-t);
                mp[r]=t;
            }

            if(v.size()>0)
            cout<<i+(*v.begin())<<"\n";
            else
                cout<<"-1\n";
        }
    }
