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
map<int,int>mp;
bool check(int n)
{
    while(n>0){
        int cur=n%10;
        n/=10;
        if(mp[cur])
            return 0;
    }


return 1;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,k;
    cin>>n>>k;
    for(int i=0; i<k; i++)
    {
        int a;
        cin>>a;
        mp[a]++;
    }
    for(int i=n; i<=MAX; i++)
    {
        if(check(i))
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
