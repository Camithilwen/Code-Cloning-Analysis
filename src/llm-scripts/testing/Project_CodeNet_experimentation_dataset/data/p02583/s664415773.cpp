#include "bits/stdc++.h"
using namespace std;
#define ff first
#define ss second
#define pb push_back
typedef long long ll;
#define db(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<'\n'
const int inf = 1e9+7;
const int N = 1e6+9;

int main() {
    ios_base::sync_with_stdio(0);
    int a,b,n;
    cin>>n;
    // set<int> st;
    vector<int> v;
    for(int i=0;i<n;++i) {
        cin>>a;
        // st.insert(a);
        v.pb(a);
    }
    // for(int p: st) {
        // v.pb(p);
    // }
    sort(v.begin(), v.end());
    int cnt=0;
    for(int i=0;i<v.size();++i) {
        // cout<<v[i]<<endl;
        for(int j=i+1;j<v.size();++j) if(v[j]!=v[i]) {
            for(int k=j+1;k<v.size();++k) if(v[k]!=v[i] && v[k]!=v[j]) {
                if(v[i]+v[j]>v[k]) {
                    // cerr<<v[i]<<" "<<v[j]<<" "<<v[k]<<endl;
                    // cerr<<" "<<i+1<<" "<<j+1<<" "<<k+1<<endl;
                    ++cnt;
                }
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}