#include<bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename K,typename V>
using umap = unordered_map<K,V>;
template <typename V>
using uset = unordered_set<V>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define REP(i,n) for(int i=0;i<n;i++)
#define REPD(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define ALL(v) v.begin(),v.end()

#define INF 1'000'000'000'000 //10^12
#define MOD 1'000'000'007

int main(){

    int n;
    cin >> n;
    int a[n];

    REP(i,n){
        cin >> a[i];
    }

    uset<int> a_set;

    REP(i,n){
        if(a_set.find(a[i]) == a_set.end()){
            a_set.insert(a[i]);
        }else{
            a_set.erase(a[i]);
        }
    }

    cout << a_set.size() << endl;

    return 0;
}
