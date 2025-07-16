#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <string.h>
#include <iomanip>
#include <numeric>
#include <cstdlib>
#include <cstdint>
#include <cmath>
#include <functional>
#include <limits>
#include <cassert>

using namespace std;

/* template */

using ll = long long;

void debug_out() { std::cout << std::endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << H << " ";
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cout << "debug: "; debug_out(__VA_ARGS__)
#else
#define debug(...) 
#endif

#define rep(i, a, n) for (int i = (int)(a); i < (int)(n); i++)
#define rrep(i, a, n) for (int i = ((int)(n-1)); i >= (int)(a); i--)
#define Rep(i, a, n) for (long long i = (long long)(a); i< (long long)(n); i++)
#define RRep(i, a, n) for (long long i = ((long long)(n-1ll)); i>=(long long)(a); i--)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
  for (std::size_t i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
  return os;
}

struct Edge{
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w){ }
};

struct edge{
    int from;
    int to;
    int weight;
    edge(int f,int t,int w) : from(f), to(t), weight(w){ }
};


using Graph = vector<vector<Edge>>;
using graph = vector<vector<int>>;
using edges = vector<edge>;

template <class T>
inline bool chmin(T &a, T b){
    if (a > b){
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b){
    if (a < b){
        a = b;
        return true;
    }
    return false;
}

template <class T>
T lcm(T a, T b){
    return (a*b)/gcd(a,b);
}

bool isPalindrome(string s){
    string t = s;
    reverse(all(t));
    return s==t;
}

constexpr ll LNF = 1e18+7;

constexpr int INF = 1e9+7;



vector<int> dx = {-1,0,1,0,-1,1,-1,1};
vector<int> dy = {0,-1,0,1,1,-1,-1,1};

/* template */

int main(){
    ll n; cin >> n;
    string a;
    ll left = 0ll, right = n-1ll;
    cout << 0 << endl;
    cin >> a;
    if(a=="Vacant"){
        return 0;
    }
    string b;
    while(b!="Vacant"){
        ll mid = (left+right)/2ll;
        cout << mid << endl;
        cin >> b;
        if(b=="Vacant") return 0;
        if(mid%2==0){
            if(a==b){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        else{
            if(a!=b){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
    }
}