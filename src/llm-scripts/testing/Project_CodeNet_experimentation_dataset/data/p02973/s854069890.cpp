//
// Created on 2020/08/10.
//


#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <ios>
#include <iomanip>
#include <numeric>

#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const long long LINF =1e18;
const int INF = 1e9;



int main() {

    int n;
    cin>>n;
    vector<int>L;
    int init;
    cin>>init;
    L.push_back({init});
    for (int i = 1; i < n; ++i) {
        int a;
        cin>>a;
        int ok = L.size() - 1;
        int ng = -1;
        int mid = (ok + ng) / 2;
        while(1 < abs(ok - ng)){
            if(L[mid] < a){
                ok = mid;
            }else{
                ng = mid;
            }
            mid = (ok + ng) / 2;
        }
        if(L[ok] < a){
            L[ok] = a;
        }else if(L[ok] >= a){
            L.push_back(a);
        }}
    cout<<L.size()<<endl;
    return 0;
}
