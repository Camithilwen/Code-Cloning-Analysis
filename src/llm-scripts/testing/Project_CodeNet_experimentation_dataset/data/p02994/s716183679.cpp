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
ll ADD(ll ADD_X,ll ADD_Y)
{
    return (ADD_X+ADD_Y)%MOD;
}
ll SUB(ll SUB_X,ll SUB_Y)
{
    return ((SUB_X-SUB_Y)+MOD)%MOD;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,x;
    cin>>n>>x;
    vector<int>v;
    int sum=0;
    for(int i=1; i<=n; i++)
    {
        int a;
        a=x+i-1;
        sum+=a;
        v.push_back(a);
    }
    int ans=0,dif=INT_MAX;
    for(int i=0;i<n;i++){
        int cur=sum-v[i];
        int now=abs(abs(cur)-abs(sum));
        if(now<dif){
            dif=now;
            ans=cur;
        }
    }
    cout<<ans<<endl;

    return 0;
}
