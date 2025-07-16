#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(){
    int n; cin>>n;
    deque<int> d;
    rep(i,n){
        int a; cin>>a;
        int p = lower_bound(d.begin(),d.end(),a) - d.begin();
        if(p==0) d.push_front(a);
        else d[p-1] = a;
    }
    cout << d.size() << endl;
}