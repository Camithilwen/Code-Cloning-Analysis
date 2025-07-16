#include<bits/stdc++.h>
using namespace std;
bool comp(pair<long long int,long long int>a,pair<long long int,long long int>b)
{
    if(a.first==b.first)
    {
        if(a.second<=b.second)
        return true;
        else
        return false;
    }
    if(a.first>b.first)
    return true;
    else return false;
}
long long int gcd(long long int bdda,long long int chota)
{
    if(chota==0)
        return bdda;
    return gcd(chota,bdda%chota);
}
void solve()
{
    int A, B, M;
    cin >> A >> B >> M;
    vector<int> a(A);
    vector<int> b(B);
    for (int i = 0; i < A; i++)cin >> a[i];
    for (int i = 0; i < B; i++)cin >> b[i];
    int minA = *min_element(a.begin(), a.end());
    int minB = *min_element(b.begin(), b.end());
    int ans = minA+minB;
    for (int i = 0; i < M; i++) {
    int x, y, c;
    cin >> x >> y >> c; x--; y--;
    ans = min(ans, a[x] + b[y] - c);
    }
    cout << ans << endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;    
    t=1;

    //cin>>t;
    while(t--)
    {
        solve();
    }
}
