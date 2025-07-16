#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long
#define vll vector<ll>
#define ld long double
#define pll pair<ll,ll>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define oset tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define osetll tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ook order_of_key
#define fbo find_by_order
const int MOD=1000000007;
long long int inverse(long long int i){
    if(i==1) return 1;
    return (MOD - ((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
}
ll POW(ll a,ll b)
{
    if(b==0) return 1;
    if(b==1) return a%MOD;
    ll temp=POW(a,b/2);
    if(b%2==0) return (temp*temp)%MOD;
    else return (((temp*temp)%MOD)*a)%MOD;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    string s[n];
    ll a[n],b[n];
    vector<pair<ll,ll> > v1,v2;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        ll mx=0,temp=0;
        for(int j=0;j<s[i].size();j++)
        {
            if(s[i][j]==')') temp++;
            else temp--;
            mx=max(temp,mx);
        }
        a[i]=mx;
        temp=0;
        ll mn=0;
        for(int j=s[i].size()-1;j>=0;j--)
        {
            if(s[i][j]=='(') temp++;
            else temp--;
            mn=max(mn,temp);
        }
        b[i]=mn;
        //cout<<a[i]<<" "<<b[i]<<" ";
        if( (b[i]-a[i]) >0) v1.PB(MP(a[i],i));
        else v2.PB(MP(-b[i],i));
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    stack<ll> st;
    ll flag=0;
    for(int i=0;i<v1.size();i++)
    {
        string k=s[v1[i].S];
        for(int j=0;j<k.size();j++)
        {
            if(k[j]=='(') st.push(1);
            else
            {
                if(st.empty()) {flag=1; break;}
                else st.pop();
            }
        }
        if(flag==1) break;
    }
    if(flag==0)
    {
        for(int i=0;i<v2.size();i++)
        {
            string k=s[v2[i].S];
            for(int j=0;j<k.size();j++)
            {
                if(k[j]=='(') st.push(1);
                else
                {
                    if(st.empty()) {flag=1; break;}
                    else st.pop();
                }
            }
            if(flag==1) break;
        }
    }
    if(flag==0 && st.empty()) cout<<"Yes";
    else cout<<"No";
}
