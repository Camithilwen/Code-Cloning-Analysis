#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long fpb(long long x, long long y) { 
    return (y == 0) ? x : fpb(y, x % y); 
}
long long kpk(long long x, long long y) { 
    return x * (y / fpb(x, y)); 
}
bool cmp(long long a,long long b)
{
    return a>b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    vector <char> ans;
    char temp;
    while(n>0){
        n--;
        temp='a'+n%26;
        //cout<<temp<<endl;
        ans.push_back(temp);
        n/=26;
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i];
    }
    cout<<endl;
}