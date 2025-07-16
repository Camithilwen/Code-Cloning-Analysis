#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main(){
    int n; cin>> n;
    vector<ll> a(100000);
    set<ll> memo;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(memo.count(a[i])){
            memo.erase(a[i]);
        }else{
            memo.insert(a[i]);
        }
    }
    int ans = memo.size();
    cout << ans << endl;
    return 0;
}