#include <bits/stdc++.h>
using namespace std;


#define fast_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
typedef long long int lli;
typedef long long ll;
typedef long double ld;


signed main(){
    fast_IO;
    int t=1;
    //cin>>t;
    while(t--){
        ld n,b;
        cin>>n>>b;
        ll nb = b*100+0.5;
        cout<<(n*nb)/100;
    }   
    return 0;
}
