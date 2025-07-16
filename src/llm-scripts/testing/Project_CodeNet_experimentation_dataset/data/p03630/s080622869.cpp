#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int solve(vector<int> v)
{
    int n=v.size();
    vector<int> l(n,-1);
    stack<array<int,2>> s;
    s.push({-1,-1});
    for(int i=0;i<n;i++)
    {
        while(s.top()[0]>=v[i]) s.pop();
        l[i]=s.top()[1];
        s.push({v[i],i});
    }
    vector<int> r(n,n);
    while(!s.empty()) s.pop();
    s.push({-1,n});
    for(int i=n-1;i>=0;i--)
    {
        while(s.top()[0]>=v[i]) s.pop();
        r[i]=s.top()[1];
        s.push({v[i],i});
    }
    int res=0;
    for(int i=0;i<n;i++) res=max(res,(v[i]+1)*(r[i]-l[i]));
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    for(int i=0;i<h;i++) cin >> s[i];
    vector<vector<int>> sum(h-1,vector<int>(w-1,0));
    for(int i=0;i<h-1;i++) for(int j=0;j<w-1;j++) sum[i][j]=((((s[i][j]=='#')^(s[i][j+1]=='#')^(s[i+1][j]=='#')^(s[i+1][j+1]=='#'))%2)==0);
    int res=max({h,w,solve(sum[h-2])});
    for(int i=h-3;i>=0;i--)
    {
        for(int j=0;j<w-1;j++) if(sum[i][j]==1) sum[i][j]+=sum[i+1][j];
        res=max(res,solve(sum[i]));
    }
    cout << res << "\n";
    return 0;
}
