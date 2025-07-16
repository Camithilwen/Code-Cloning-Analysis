#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
    string s;cin >>s;
    ll n=s.size();
    bool flg=true;
    if(n%2==1)flg=false;
    else {
        for (int i = 0; i < n; i += 2) {
            if (s.substr(i, 2) != "hi")flg = false;
        }
    }
    if(flg)puts("Yes");
    else puts("No");
    return 0;
}
