#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MOD 1000000007
#define N 1000000
#define pb push_back
int a[N][2];
signed main()
{
    SPEED;
    int n;
    cin>>n;
    string s[n];
    for(int i=0;i<n;++i)
    {
        cin>>s[i];
        int c1=0,c2=0;
        for(int j=0;j<s[i].length();++j)
        {
            if(s[i][j]==')')
                c1++;
            else 
                c2++;
            a[i][0]=max(a[i][0],c1-c2);
        }
        c1=0;c2=0;
        int l=s[i].length();
        for(int j=l-1;j>=0;--j)
        {
            if(s[i][j]=='(')
                c1++;
            else 
                c2++;
            a[i][1]=max(a[i][1],c1-c2);
        }
    }
    vector<pair<int,int>> s1,s2;
    for(int i=0;i<n;++i)
    {
        if(a[i][1]-a[i][0]>=0)
            s1.pb({a[i][0],a[i][1]});
        else
            s2.pb({a[i][1],a[i][0]});
    }
    sort(s1.begin(),s1.end());
    sort(s2.rbegin(),s2.rend());
    int j=0,k=0,sum=0,f=0;
    for(int i=0;i<n;++i)
    {
        if(j<s1.size())
        {
            sum-=s1[j].first;
            if(sum<0)
                break;
            sum+=s1[j].second;
            j++;
        }
        else
        {
            sum-=s2[k].second;
            if(sum<0)
                break;
            sum+=s2[k].first;
            k++;
        }
    }
    if(sum!=0)
        cout<<"No";
    else
        cout<<"Yes";
}


