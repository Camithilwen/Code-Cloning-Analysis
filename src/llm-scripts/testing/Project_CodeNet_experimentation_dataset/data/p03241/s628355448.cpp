#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


int main(){
    int n,m;
    cin >> n >> m;
    set<int> s;
    for(int i = 2;i<=sqrt(m);i++){
        if(m%i==0) {
            s.insert(i);
            s.insert(m/i);
        }
    }
    s.insert(m);

    int ans = 1;

    for(auto it = s.begin();it!=s.end();it++){
        if((*it)<=m/n) ans = *it;
        else break;
    }

    cout << ans << endl;

    //for(auto it=s.begin();it!=s.end();it++) cout << *it << endl;

 }