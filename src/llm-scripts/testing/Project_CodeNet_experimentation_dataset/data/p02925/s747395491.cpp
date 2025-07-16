#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll income[1010011];
vector<ll>adj[1010011];
map<ll,ll>m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll num;
    ll cur=1;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i+1;j<=n;j++)
        {
            if(i!=j)
            {
                ll mini=min(i,j);
                ll maxi=max(i,j);
                m[mini*10000+maxi]=cur;
                cur++;
            }
        }
    }
    for(ll i=1;i<=n;i++)
    {
        ll num1;
        cin>>num1;
        ll i1=m[min(i,num1)*10000+max(i,num1)];
        for(ll j=2;j<n;j++)
        {
           cin>>num;
           ll mini=min(i,num);
           ll maxi=max(i,num);
           ll i2=m[min(i,num)*10000+max(i,num)];
           //cout<<i1<<" "<<i2<<endl;
           adj[i1].push_back(i2);
           income[i2]+=1;
           //cout<<i2<<" "<<income[i2]<<endl;
           i1=i2;
        }
    }
    //cout<<income[1]<<" "<<income[2]<<" "<<income[3]<<endl;
    //for(ll i=1;i<cur;i++)
    //    cout<<income[i]<<" "<<i<<endl;;
    vector<ll>v;
    ll ans=1;
    for(ll i=1;i<cur;i++)
    {
        if(income[i]==0)
        {
            v.push_back(i);
        }

    }
    //cout<<v.size()<<endl;
    if(v.size()==0)
    {
        cout<<"-1";
        return 0;
    }
    while(1)
    {
        vector<ll>v1;
        ll flag=0;
        for(ll i=0;i<v.size();i++)
        {
            for(ll j:adj[v[i]])
            {
                income[j]-=1;
                if(income[j]==0)
                {
                    v1.push_back(j);
                    flag=1;
                }
            }
        }
        if(flag==1)
        {
            ans++;
            v.clear();
            for(ll i=0;i<v1.size();i++)
            {
                v.push_back(v1[i]);
            }
        }
        else{
            break;
        }
    }
    for(ll i=1;i<cur;i++)
    {
        if(income[i]>0)
        {
            cout<<"-1";
            return 0;
        }
    }
    cout<<ans;
	return 0;
}