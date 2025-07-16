#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll MOD=1000000007;
int main(void){
    int n;
    cin>>n;
    int ans=0;
    int a;
    set<int> s;
    while(n--){
        cin>>a;
        auto itr=s.lower_bound(a);
        if(a==(*itr)){
            ans--;
            s.erase(a);
        }else{
            ans++;
            s.insert(a);
        }
    }
    cout<<ans<<endl;
    
}
