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

ll y[10000005];

int main() {
    string s; cin >> s;
    int n = s.size();

    map<char,int> mp;
    rep(i,n) mp[s[i]]++;

    rep(i,26){
        if(!mp[char (i+97)]){
            cout << s + char(i+97) << endl;
            return 0;
        }
    }
    if(s == "zyxwvutsrqponmlkjihgfedcba") cout << -1 << endl;
    else {
        for(int i = n-1; i >= 1; i--){
            if(s[i-1] < s[i]){
                rep(j,i-1){
                    cout << s[j];
                }
                for(int j = n-1; j>=1;j--){
                    if(s[i-1] < s[j]){
                        cout << s[j];
                        return 0;
                    }
                }
                return 0;
            }
        }
    }
}
