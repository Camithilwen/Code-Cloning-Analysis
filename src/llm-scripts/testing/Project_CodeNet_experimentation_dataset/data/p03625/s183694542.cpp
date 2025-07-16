#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <set> 
# include <map>
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
    ll n; cin>>n;
    vector<ll> v(n);
    REP(i,n)cin>>v[i];
    sort(ALL(v));
    vector<ll> sides;
    vector<ll> list;
    map<ll,ll> mp;
    REP(i,n){
        ll a=v[i];
        if(mp.find(a)!=mp.end()){
            mp.at(a)++;
            list.push_back(a);
        }else{
            mp.insert(make_pair(a,1));
        }
    }
    REP(i,SIZE(list)){
        ll s=list[i];
        while(mp.at(s)/=2){
            sides.push_back(s);
        }
    }
    ll ans;
    if(SIZE(sides)<2){
        ans=0;
    }else{
        sort(ALL(sides),greater<>());
        ans=sides[0]*sides[1];
    }
    cout<<ans<<endl;
    return 0;
}
