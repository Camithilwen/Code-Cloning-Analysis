#include<bits/stdc++.h> 
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

bool judge(int x, vector<int> d){
    bool ans = true;
    while (x > 0){
        rep(i, d.size()){
            if (x % 10 == d[i]) ans = false;
        }
        x /= 10;
    }
    return ans;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> d(k);
    rep(i, k) cin >> d[i];
    for(int i = n; i < 1000000; i++){
        if (judge(i, d)){
            cout << i << endl;
            return 0;
        }
    }
}
