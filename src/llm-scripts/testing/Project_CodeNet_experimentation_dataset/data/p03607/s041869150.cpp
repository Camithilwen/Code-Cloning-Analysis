#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x)) //最大値を求める
#define MIN(x) *min_element(ALL(x)) //最小値を求める
typedef long long ll;
typedef long double ld;
int main(){
    set<ll> v;
    ll n;cin>>n;
    REP(i,n){
        ll a;cin>>a;
        if(v.find(a)!=v.end()){
            v.erase(a);
        }else{
            v.insert(a);
        }
    }
    cout<<v.size()<<endl;
    return 0;
}
