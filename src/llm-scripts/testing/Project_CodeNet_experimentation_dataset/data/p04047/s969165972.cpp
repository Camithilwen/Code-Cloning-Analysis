#include<bits/stdc++.h>
using namespace std;
#define LL  long long
#define pii pair<int, int>


int main(){
    int n; cin>>n;
    vector<int> v;
    for(int i = 1; i <= 2*n; i++){
        int x; cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int res = 0;
    for(int i = 0; i < (2*n)-1; i += 2){
        res += min(v[i], v[i+1]);
    }

    cout<<res<<'\n';
}


