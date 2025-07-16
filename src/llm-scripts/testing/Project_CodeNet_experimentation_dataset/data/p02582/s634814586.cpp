/*___________Bismillahir Rahmanir Rahim__________*/
//Think positive, be positive and never use negative words
#include<bits/stdc++.h>
#define ll               long long int
#define uni(a)           a.erase(unique(a.begin(),a.end()),a.end())
#define vsum(a)          accumulate(a.begin(),a.end(),0)
#define vmax(a)          *max_element(a.begin(),a.end())
#define vmin(a)          *min_element(a.begin(),a.end())
#define gcd(a,b)         __gcd(a,b)
#define lcm(a,b)         (a/gcd(a,b))*b
#define yes              cout<<"YES"<<endl
#define no               cout<<"NO"<<endl
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin>>s;
    ll x=(s[0]=='R');
    ll y=(s[1]=='R');
    ll z=(s[2]=='R');
    if(x && y && z) cout<<3<<endl;
    else if((x && y) || (y && z)) cout<<2<<endl;
    else if(x || y || z) cout<<1<<endl;
    else cout<<0<<endl;
    return 0;
}
/*_________________Alhamdulillah_________________*/
