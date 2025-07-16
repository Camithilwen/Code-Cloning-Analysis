#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <random>
#include <cassert>
#include <numeric>
#define ll long long int
#define LL unsigned long long
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
using namespace std;

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};
const int MOD = 1000000007;



int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), sum(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());

    sum[0] = a[0];
    rep(i,n-1) sum[i+1] = sum[i] + a[i+1];

    rep(i,n) {
        if(sum[i] == x){
            cout << i + 1 << endl;
            return 0;
        }else if(sum[i] > x) {
            cout << i << endl;
            return 0;
        }
    }
    cout << n - 1 << endl;
}