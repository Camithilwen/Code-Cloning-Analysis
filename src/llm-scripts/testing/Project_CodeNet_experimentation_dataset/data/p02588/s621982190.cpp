#include<bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int,int>P;
map<P,int>mp;
int main(){ 
    int n;
    cin>>n;
    while(n--){ 
        ld s;
        cin>>s;
        ll k=ll(s*1000000000.0+0.5);
        ll cnt2=0,cnt5=0;
        while(k%2==0){ 
            k/=2,cnt2++;
        }
        while(k%5==0){ 
            k/=5;cnt5++;
        }
        mp[make_pair(cnt2,cnt5)]++;
    }
    ll ans=0;
    for(auto&v:mp){ 
        for(auto&u:mp){ 
            if(v.first.first+u.first.first>=18&&v.first.second+u.first.second>=18)
            {
               if(v==u)ans+=1ll*v.second*(v.second-1);
               else ans+=1ll*v.second*u.second;
            }
        }
    }
    cout<<ans/2<<endl;
    return 0;
}
