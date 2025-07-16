#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin>>n;
    vector<ll >v;
    vector<ll >vp;

    ll i,j,k;
    ll a,b;
    for(i=0; i<n; i++)
    {
        cin>>a;
        v.push_back(a);

    }
    for(i=0; i<n; i++)
    {
        cin>>a;
        vp.push_back(a);

    }
    reverse(vp.begin(),vp.end());
    ll f=0;

    ll l=0,r=n-1;
    for(i=0; i<n; i++)
    {
        if(v[i]==vp[i])
        {
            if(v[l]!=vp[i]&&v[i]!=vp[l])
            {
                //  cout<<l<<"  f "<<i<<endl;

                swap(vp[l],vp[i]);
                  l++;
            }
            else if(v[r]!=vp[i]&&v[i]!=vp[r] )
            {
                  //   cout<<l<<"  s "<<endl;
                f=0;
                swap(vp[r],vp[i]);
                r--;
            }
            else
            {
                f=1;
                break;
            }
        }
    }

    if(f)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<< "Yes"<<endl;
        for(ll i=0; i<n; i++)
        {
            cout<<vp[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

