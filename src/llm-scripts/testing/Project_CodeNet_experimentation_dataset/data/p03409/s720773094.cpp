///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           node(a,b,c)                 mp(mp(a,b),c)
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=100005;
map<int,pi>yo;
 main()

{
    fast
    int n;
    cin>>n;
    f(i,1,n)
    {
        int x,y;
        cin>>x>>y;
        yo[x]=(mp(y,0));
    }
    f(i,1,n)
    {
        int x,y;
        cin>>x>>y;
        yo[x]=(mp(y,1));
    }
    int ses=0;
    set<int>s;
    set<int>::iterator it;
    for(auto z:yo)
    {
        int x=z.fi;
        int typ=z.si.si;
        int y=z.si.fi;
        if(typ==0)
        {
            s.insert(y);
        }
        else
        {
           if(s.empty())continue;
           it=s.upper_bound(y);
           if(it==s.begin())continue;
           it--;
           s.erase(it);
           ses++;

        }
    }
    cout<<ses<<"\n";
    return 0;

}



































