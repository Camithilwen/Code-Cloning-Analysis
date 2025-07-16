#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    map<int, int> mp;
    bool is = true;
    rep(i, N){
        int a;
        cin >> a;
        if(mp.count(a) != 0){
            is = false;
            break;
        }else{
            mp[a]++;
        }
    }
    if(is) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}