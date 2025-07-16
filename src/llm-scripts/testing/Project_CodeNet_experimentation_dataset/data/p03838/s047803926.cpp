#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}

int main()
{
    ll x,y;
    cin >> x >> y;
    ll A = abs(abs(x)-abs(y));
    ll B = 0;
    if(( x>0 && y>0 )||( x<0 && y<0 )){
        if((x>0 && abs(x) > abs(y)) || (x<0 && abs(x) < abs(y)))B = 2;
    }else{
        B=1;
        if((x<0 && y==0) || (x==0 && y>0))B = 0;
    }
    cout << (A+B) << endl;
}