#include<bits/stdc++.h>
using namespace std;

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using ll=long long;
using ld=long double;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

template<typename T> bool chmin(T &a,const T b){if(a>b){a=b; return true;}return false;}
template<typename T> bool chmax(T &a,const T b){if(a<b){a=b; return true;}return false;}



int main(){
    int N, M; cin >> N >> M;
    vi L(M), R(M);
    for(int i=0; i<M; i++){
        cin >> L[i] >> R[i];
    }

    int l=L[0], r=R[0];
    bool flag=0;
    for(int i=1; i<M; i++){
        if(max(l, L[i]) <= min(r, R[i])){
            l=max(l, L[i]);
            r=min(r, R[i]);
        }
        else flag=true;
    }
    if(flag) cout << 0 << endl;
    else cout << r-l+1 << endl;
    return 0;
}