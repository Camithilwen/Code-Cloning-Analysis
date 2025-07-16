#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define vv vector< vector< int > >
#define ll long long
#define ALL(a) (a).begin(), (a).end()
const long long mod = 1000000000 + 7;
const long long INF = 9e18;
const double PI = 3.14159265358979323846;

ll gcd(ll a, ll b){if (b == 0) return a;return gcd(b, a % b);}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int stringcount(string s, char c) {
    return count(s.cbegin(), s.cend(), c);
}

int main(){
    string S, ans="AC";
    cin >> S;
    if(S[0] != 'A') ans = "WA";
    else {
        S[0] = 'a';
        string sub;
        sub = S.substr(2, S.length()-3);
        if(stringcount(sub, 'C') != 1) ans = "WA";
        else {
            S[S.find('C')] = 'c';
            for(char c : S) {
                if(!islower(c)) {
                    ans = "WA";
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}


