#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int n;
string s;
int cache[1000004][3];
int dp(int pos,int carr)
{
    if(pos==n)
        return carr;
    int &ans=cache[pos][carr];
    if(ans!=-1)
        return ans;
    ans=1e18;
    for(int i=0;i<10;i++)
    {
        int dig1=i;
        int dig2=(i+carr+s[pos]-'0')%10;
        ans=min(ans,dig1+dig2+dp(pos+1,(i+carr+s[pos]-'0')/10));
    }
    return ans;
}
int32_t main() 
{
    cin>>s;
    reverse(s.begin(),s.end());
    n=s.length();
    memset(cache,-1,sizeof(cache));
    print(dp(0,0));
}   
