//Tanzim bin nasir
#include<bits/stdc++.h>
typedef long long ll;
#define ff first
#define ss second
using namespace std;
void fast()
{
ios::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
}
ll gcd(ll a,ll b)
{
    if(b==0)
    return a;
    else
    gcd(b,a%b);
}
ll lcd(ll a,ll b)
{
    return (a*b)/gcd(a,b);
}
int main()
{
    int n,ans=1,mn,temp;
    cin>>n>>mn;
    for(int i=1;i<n;i++)
    {
        cin>>temp;
        if(temp<=mn)
        {
            mn=temp;
            ++ans;
        }
    }
    cout<<ans<<endl;
}
