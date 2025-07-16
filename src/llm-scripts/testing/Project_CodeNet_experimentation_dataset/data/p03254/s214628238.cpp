#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <vector>
#include <cstring>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uld = unsigned long long;
using P = pair<int,int>;
const ll mod = 1e9+7;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
template<class T> inline bool chmax(T &a,T& b){if(a < b){a = b; return true;} else return false;}
template<class T> inline bool chmin(T &a,T& b){if(a > b){a = b; return true;} else return false;}
int main(){
    int n,x;
    cin >> n >> x;
    int num[n],cum[n+1]={0};
    rep(i,n){
        cin >> num[i];
    }
    sort(num,num+n);
    rep1(i,n){
        cum[i] = cum[i-1] + num[i-1];
    }
    int ans = n;
    rep(i,n+1){
        if(i == n){
            if(x != cum[n]){ ans--;}
            break;
        }
        if(cum[i] <= x && x < cum[i+1]){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}