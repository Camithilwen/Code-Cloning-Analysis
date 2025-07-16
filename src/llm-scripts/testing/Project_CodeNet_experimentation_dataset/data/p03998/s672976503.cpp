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

const ll INF = 1LL << 60;
const ll MOD = 1e9+7;

int main()
{
    string A,B,C;
    cin >> A >> B >> C;
    queue<char> qA,qB,qC;
    for(auto a:A){
        qA.push(a);
    }
    for(auto b:B){
        qB.push(b);
    }
    for(auto c:C){
        qC.push(c);
    }
    bool flag = true;
    char now = qA.front();
    qA.pop();
    string ans;
    while(flag){
        switch(now){
        case 'a':
            if(qA.empty()){
                ans = "A";
                flag = false;
            }else{
                now = qA.front();
                qA.pop();
            }
            break;
        case 'b':
            if(qB.empty()){
                ans = "B";
                flag = false;
            }else{
                now = qB.front();
                qB.pop();
            }
            break;
        case 'c':
            if(qC.empty()){
                ans = "C";
                flag = false;
            }else{
                now = qC.front();
                qC.pop();
            }
            break;
        default:
            break;
        }
    }
    cout << ans << endl;
}