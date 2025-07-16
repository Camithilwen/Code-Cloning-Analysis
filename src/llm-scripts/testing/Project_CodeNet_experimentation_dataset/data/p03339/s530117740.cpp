#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int pre_e[MAX],pre_w[MAX],suf_w[MAX],suf_e[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);

    int len;
    string s;
    cin>>len;
    cin>>s;
    for(int i=1; i<=len; i++)
    {
        pre_e[i]=pre_e[i-1];
        pre_w[i]=pre_w[i-1];
        if(s[i-1]=='E')
            pre_e[i]++;
        else
            pre_w[i]++;
    }
    for(int i=len; i>=1; i--)
    {
        suf_e[i]=suf_e[i+1];
        suf_w[i]=suf_w[i+1];
        if(s[i-1]=='E')
            suf_e[i]++;
        else
            suf_w[i]++;
    }
    int mx=INT_MAX;
    for(int i=1;i<=len;i++){
        int x=pre_w[i-1]+suf_e[i+1];
        mx=min(x,mx);
    }
    cout<<mx<<endl;

    return 0;
}
