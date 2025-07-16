// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
 
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <numeric>
#include <time.h>
#include <stack>
#include <bitset>

#define prev asasddlsa
#define rank aljds

#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i >= l; i++)
 
using namespace std;
 
typedef long long ll;
typedef double dbl;
 
template<typename T>
void print(const vector<T>& s){
    for (auto x : s)
        cout << x << " ";
    cout << endl;
}
 
template<class T>   
void print(const T* s, int n){
    for (int i = 0; i < n; i++)
        cout << s[i] << ' ';
    cout << endl;
}

template<class T>
void print(vector<vector<T>> s){
    for (int i = 0; i < s.size(); i++)
        print(s[i]);
}

int solve(){
    int n;
    cin >> n;
    vector<int> s(2 * n);
    for (int& x : s)
        cin >> x;
    sort(s.begin(), s.end());
    int res = 0;
    for (int i = 0; i < 2 * n; i += 2){
        res += s[i];
    }
    cout << res << endl;
    return 0;
}

int main(){
    srand(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(10);
    cout << fixed; 
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
