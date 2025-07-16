#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <deque>
#include <queue>
#include <tuple>
#include <queue>
#include <functional>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <complex>
#include <iterator>
#include <array>
#include <memory>
#include <stack>
#define vi vector<int>
#define vvi vector<vector<int> >
#define ll long long int
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ld long double
#define INF 1e9
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define all(in) in.begin(), in.end()
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
#define MAX 9999999
using namespace std;
typedef pair<int, int> pii;
typedef pair<double,double>pdd;
typedef pair<ll,ll>pll;
int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int lcm( int m, int n ){
    if ( ( 0 == m ) || ( 0 == n ) )
        return 0;
    
    return ((m / gcd(m, n)) * n); // lcm = m * n / gcd(m,n)
}
int main(){
    int n; cin>>n;
    vi v(n,0);rep(i,n)cin>>v[i];
    sort(all(v));
    for(int i=1;i<=v[0];i++){
        bool flag=true;
        rep(j,n){if(v[j]%i)flag=false;}
            if(flag)cout<<i<<endl;
    }
}