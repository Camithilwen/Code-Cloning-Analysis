#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define each(it,v) for(auto &it : v)
#define mod 1000000007
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vl vector<long>
#define P pair<int,int>
using namespace std;

#define pi 3.1415926535897932384

main()
{
        int n; cin>>n;
        string a,b,c; cin>>a>>b>>c;

        int ans=0;

        rep(i,n)
        {
                set<char> s;
                s.insert(a[i]);
                s.insert(b[i]);
                s.insert(c[i]);

                if(s.size()==2)ans++;
                if(s.size()==3)ans+=2;
        }
        cout<<ans<<endl;
}