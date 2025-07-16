#include<bits/stdc++.h>
#define pb push_back
#define sf scanf
#define pf printf
#define FAST ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
using namespace std;
#define ll long long
const int N=2e5+9;
void slv()
{
    int n;
    cin>> n;
    int a[n+3],b[n+3];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    int l=0,r=n-1;
    reverse(b,b+n);
    for(int i=0;i<n;i++) {
        if(a[i]==b[i]) {
            if(b[l]!=b[i] && a[l]!=b[i]) {
                swap(b[l],b[i]);
                l++;
            } else if(b[r]!=b[i] && a[r]!=b[i]) {
                swap(b[r],b[i]);
                r--;
            } else {
                puts("No");
                return ;
            }
        }
    }
    for(int i=0;i<n;i++) {
        if(a[i]==b[i]) {
            puts("No");
            return ;
        }
    }
    puts("Yes");
    for(int i=0;i<n;i++) cout<<b[i]<< " ";
}
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    int t;
    t=1;
    int cs=1;
    while (t--)
    {
        //cout<<"Case : "<<cs++<<endl;
        slv();
    }
    return 0;
}