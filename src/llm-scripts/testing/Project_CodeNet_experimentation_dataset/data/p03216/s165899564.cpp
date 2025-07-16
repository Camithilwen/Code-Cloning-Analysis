/*
これを入れて実行
g++ code.cpp
./a.out
 */
 
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <unordered_map>
#include <cmath>
#include <math.h>
#include <tuple>
#include <iomanip>
#include <bitset>
#include <functional>

#define all(x) (x).begin(),(x).end()
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
int dy4[4] = {-1, 0, +1, 0};
int dx4[4] = {0, +1, 0, -1};
int dy8[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
 
const long long INF = 1LL << 60;
const ll MOD = 1e9 + 7;
 
bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
    return f.second > s.second;
}
 
ll gcd(ll a, ll b){
	if (b == 0)return a;
	return gcd(b, a % b);
}
 
ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}
 
ll nCr(ll n, ll r){
    if(r == 0 || r == n){
        return 1;
    } else if(r == 1){
        return n;
    }
    return (nCr(n - 1, r) + nCr(n - 1, r - 1));
}
 
ll nPr(ll n, ll r){
    r = n - r;
    ll ret = 1;
    for (ll i = n; i >= r + 1; i--) ret *= i;
    return ret;
}
 
//-----------------------ここから-----------
int main(void){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<int> K(q);
    for(int i = 0; i < q; i++) cin >> K[i];
    for(int i = 0; i < q; i++){
        int k = K[i];
        int r = 0;
        ll dcnt = 0;
        ll dmcnt = 0;
        ll dmccnt = 0;
        ll mcnt = 0;
        for(int l = 0; l < n; l++){
            while(r < n && r - l < k){
                if(s[r] == 'D'){
                    dcnt++;
                } else if(s[r] == 'M'){
                    dmcnt += dcnt;
                    mcnt++;
                } else if(s[r] == 'C') {
                    dmccnt += dmcnt;
                }
                r++;
            }

            //cout << l <<" " << r << " " << dcnt << " " << dmcnt << " " << dmccnt << endl;

            //if(r == l) r++;

            if(s[l] == 'D'){
                dmcnt -= mcnt;
                dcnt--;
            }

            if(s[l] == 'M') mcnt--;
        }
        cout << max(0LL,dmccnt) << endl;
    }
}   