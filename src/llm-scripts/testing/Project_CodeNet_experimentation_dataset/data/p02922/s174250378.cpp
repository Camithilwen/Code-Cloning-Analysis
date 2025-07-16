#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a,b;
    cin>>a>>b;
    int ans=1;
    for(int i=0;;i++){
        if(ans>=b){
            cout<<i<<endl;
            return 0;
        }
        ans=ans-1+a;
    }
}