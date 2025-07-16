#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

template<typename T> bool chmax(T &a,const T b){if(a < b){a=b; return true;} return false;}
template<typename T> bool chmin(T &a,const T b){if(a > b){a=b; return true;} return false;}

int main(){
    /*
    int n; cin >> n;
    vi x(n), y(n);
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }
    */
    int n; cin >> n;
    vector<queue<int>> com(n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            int a; cin >> a;
            a--;
            com[i].push(a);
        }
    }
 
    set<int> prev;
    for(int i=0; i<n; i++) prev.insert(i);
    int ans=0;
    while(!prev.empty()){
        set<int> tmp;
        bool flag=false;
        for(auto p: prev){
            if(com[p].empty()) continue;
            int op=com[p].front();
            flag=true;
            if(com[op].front() == p){
                tmp.insert(p);
                tmp.insert(op);
            }
        }
        for(auto p: tmp){
            com[p].pop();
        }
        if(tmp.empty()){
            if(flag) ans=-1;
            break;
        }
        ans++;
        prev=tmp;
    }
 
    cout << ans << endl;
    return 0;
}