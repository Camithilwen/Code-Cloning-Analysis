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
ll arr[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,neg=0,mn=INT_MAX;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i]<0)
            neg++;
        int cur=abs(arr[i]);
        mn=min(mn,cur);
    }
    ll sum=0,sub=0;
    if(neg%2)
    {

        sub=mn;
    }
    for(int i=0; i<n; i++)
        sum+=abs(arr[i]);
    sum-=sub*2;
    cout<<sum<<endl;


    return 0;
}
