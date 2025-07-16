#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int mod=1000000007;
    string k;
    int d;
    cin >> k >> d;
    int n=k.size();
    vector<int> now(d,0);
    int val=0;
    for(int i=0;i<n;i++)
    {
        vector<int> nxt(d,0);
        int x=(k[i]-'0');
        for(int a=0;a<x;a++) nxt[(val+a)%d]=(nxt[(val+a)%d]+1)%mod;
        val=(val+x)%d;
        for(int j=0;j<d;j++)
        {
            for(int a=0;a<=9;a++) nxt[(j+a)%d]=(nxt[(j+a)%d]+now[j])%mod;
        }
        now=nxt;
    }
    cout << (now[0]+(val==0)-1+mod)%mod << "\n";
    return 0;
}
