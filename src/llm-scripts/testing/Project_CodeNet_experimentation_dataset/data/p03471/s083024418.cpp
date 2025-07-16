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
    int N,Y;
    cin >> N >> Y;
    int yen[] = {10000, 5000, 1000};
    int total,sub;
    REP(i,2001){
        REP(j,2001){
            total = yen[0]*i + yen[1]*j;
            sub = Y-total;
            if(0 != sub%yen[2] || sub < 0)break;
            sub /= yen[2];
            if(N == (i+j+sub)){
                cout << i << " " << j << " " << sub << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
}