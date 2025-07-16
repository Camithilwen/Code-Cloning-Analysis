#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n, ans=0, i;
    map<long long, long long> mp;
    cin >> n;
    for(i=0;i<n;i++){
        long long a;
        cin >> a;
        mp[a]++;
    }

    for(auto x : mp){
        if(x.second%2!=0) ans++;
    }
    
    cout << ans <<endl;
    return 0;
}