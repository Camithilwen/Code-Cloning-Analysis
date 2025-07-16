#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
//using namespace boost::multiprecision;
typedef long long int ll;
typedef long double ld;
#define MOD 1000000007
#define ALL(obj) (obj).begin(),(obj).end()
template<class T>inline bool chmax(T& a,T b){if (a<b){a=b;return 1;}return 0;}
template<class T>inline bool chmin(T& a,T b){if (a>b){a=b;return 1;}return 0;}
const long long INF = 1LL << 60;
bool pairCompare(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.first < secondElof.first;
}
bool pairCompareSecond(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.second < secondElof.second;
}
//四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct edge{//グラフに使うヤツ
    ll from,to,cost;
};

typedef vector<vector<edge> > G;
ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}

int main(){
    bool abc[26];
    fill(abc,abc+26,true);
    string s;
    cin >> s;
    for (ll i=0;i<s.size();i++){
        abc[s[i]-'a']=false;
    }
    for (ll i=0;i<26;i++){
        if (abc[i]){
            cout << s;
            cout << (char)('a'+i) << endl;
            return 0;
        }
    }
    if (s.size()==26){
        for (ll i=s.size()-1;i>=0;i--){
            for (ll j=(s[i]-'a');j<26;j++){
                if (abc[j]){
                     for (ll k=0;k<i;k++){
                         cout << s[k];
                     }
                     cout << (char)('a'+j) << endl;
                     return 0;
                }
            }
            abc[s[i]-'a']=true;
        }
    }
    cout << -1 << endl;
    return 0;
}
