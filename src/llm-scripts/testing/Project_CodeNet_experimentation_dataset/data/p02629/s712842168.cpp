#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll N;
    cin>>N;
    vector <ll> ans;
//    N--;
    while(N){
        ll rest=(N-1)%26;
        N--;
        N/=26;
        ans.push_back(rest);
    }
    ll len=ans.size();
    for(ll i=len-1;i>=0;i--){
        char c='a'+ans[i];
        cout<<c;
    }
    return 0;
}
