#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int ans=INT_MAX;
    string s;
    cin>>s;
    for(int i=0; i<=s.length()-3; i++)
    {
        int val=0;
        for(int j=0; j<3; j++)
        {
            val*=10;
            val+=(s[j+i]-'0');
        }
        ans=min(ans,abs(753-val));
    }
    cout<<ans<<endl;


    return 0;
}
