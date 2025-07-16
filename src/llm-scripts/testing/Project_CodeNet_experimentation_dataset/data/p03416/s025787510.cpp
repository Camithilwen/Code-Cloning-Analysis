/*Be patient && calm!
All our dreams can come true, if we have the courage to pursue them.
I fear not the man who has practiced 10,000 kicks once, but I fear the man who has practiced one kick 10,000 times.
Do not pray for an easy life, pray for the strength to endure a difficult one.
When something is important enough, you do it even if the odds are not in your favor.
First, solve the problem. Then, write the code.
Fix the cause, not the symptom.
Simplicity is the soul of efficiency.
Make it work, make it right, make it fast.
No matter how hard it gets, NEVER GIVE UP*/

#include <bits/stdc++.h>

#define pb push_back
#define MP make_pair
#define ALL(r) (r).begin(),(r).end()

typedef long long int ll;

#define FOR(i,m,n) for(ll i=(ll)(m) ; i < (ll) (n) ; ++i )
#define FORN(i,m,n) for(ll i=(ll)(m-1) ; i >= (ll) (n) ; --i )

#define RUN_FAST ios::sync_with_stdio(false);

using namespace std;



void solve()
{
    ll a,b,c,d,m,n,p,q,r,x,y,z,aa,bb,cc,dd,h; //variable
    ll i,j,k,l; //pointer
    ll cnt=0,cnt1=0,cnt2=0,cnt3=0,sum=0,mx=LLONG_MIN,mn=LLONG_MAX; //counter
    ll flag=0,flag2=0; //flag
    vector <ll> vec1,vec2,vec3;
    string s1,s2,s3;

    //PULOK SAHA
    //BMO

    cin >> a >> b;

    FOR(i,a,b+1)
    {
        s1=to_string(i);
        l = 0;
        h=s1.size()-1;
        flag=0;
        while (h > l)
        {
            if (s1[l++] != s1[h--])
            {
                flag=1;
                break;
            }
        }
        if(!flag)
            cnt++;
    }
    cout << cnt << endl;

}

int main()
{
    RUN_FAST
    //PULOK SAHA
    //BMO

    ll t=1;//test case

    //cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}






//PULOK SAHA