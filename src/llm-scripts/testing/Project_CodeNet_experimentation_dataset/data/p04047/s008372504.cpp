#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PI pair<int,int>
const int maxm=1e6+5;
int a[maxm];
int n;
signed main(){
    cin>>n;
    for(int i=1;i<=n*2;i++)cin>>a[i];
    int ans=0;
    sort(a+1,a+1+n*2);
    for(int i=1;i<=n*2;i+=2){
        ans+=min(a[i],a[i+1]);
    }
    cout<<ans<<endl;
    return 0;
}
/*

*/
