#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<int> a;
    ll sum = 0;
    a.push_back(0);
    rep(i,n){
        int c;
        cin >> c;
        a.push_back(c);
    }
    a.push_back(0);
    n += 2;
    rep(i,n-1){
        sum += abs(a[i+1] - a[i]);
    }
    for(int i = 1;i < n-1;i++){
        cout << sum - abs(a[i+1] - a[i]) -abs(a[i] - a[i-1]) + abs(a[i+1] - a[i-1]) << endl;
    }
}