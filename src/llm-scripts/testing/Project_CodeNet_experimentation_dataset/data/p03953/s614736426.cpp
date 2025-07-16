#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}
int n;
vector<ll> x;
vector<ll> d;
vector<int> mul(vector<int>&a,vector<int>&b){
    int m = b.size();
    vector<int> res(m);
    for(int i=0;i<m;i++){
        res[i] = b[a[i]];
    }
    return res;
}
vector<int> calc(vector<int>&a,ll k){
    int m = a.size();
    if(k==0){
        vector<int> res;
        rep(i,m){
            res[i] = i;
        }
        return res;
    }else if(k==1){
        return a;
    }
    if(k%2==0){
        vector<int> res;
        res = calc(a,k/2);
        return mul(res,res);
    }else{
        vector<int> res;
        res = calc(a,k/2);
        res = mul(res,res);
        res = mul(res,a);
        return res;
    }
}
int main(){
    cin >> n;
    x.resize(n);
    d.resize(n-1);
    rep(i,n)cin >> x[i];
    rep(i,n-1){
        d[i] = x[i+1]-x[i];
    }
    int m;
    ll k;
    cin >> m >> k;
    vector<int>a(m);
    rep(i,m){
        cin >> a[i];
        a[i]-=2;
    }
    vector<int>b(n-1);
    rep(i,n-1){
        b[i] = i;
    }
    rep(i,m){
        swap(b[a[i]],b[a[i]+1]);
    }
    // rep(i,n-1){
    //     cerr << b[i] << " ";
    // }
    // cerr << endl;
    vector<int> res = calc(b,k);
    // for(int i=0;i<n-1;i++){
    //     cerr << res[i] << " ";
    // }
    // cerr << endl;
    for(int i=0;i<n-1;i++){
        x[i+1] = x[i] + d[res[i]];
    }
    for(int i=0;i<n;i++){
        cout << x[i] << "\n";
    }
    return 0;
}