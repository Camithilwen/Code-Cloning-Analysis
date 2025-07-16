#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <random>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;

using ll = long long;
using vll = vector<long long>;
using pll = pair<long long, long long>;
#define rep(i,n) for(long long i(0);(i)<(n);(i)++)

void solve(long long N, std::string Str){
    //* left half record
    map< pair<string, string>, ll > rec;
    rep(S, 1<<N){
        string red, blue;
        rep(i, N){
            if(S >> i & 1){
                red.push_back(Str.at(i));
            }
            else{
                blue.push_back(Str.at(i));
            }
        }
        rec[make_pair(red, blue)]++;
    }
    ll cnt = 0;
    rep(S, 1<<N){
        string red, blue;
        rep(i, N){
            if(S >> i &1){
                red.push_back(Str.at(i+N));
            }
            else{
                blue.push_back(Str.at(i+N));
            }
        }
        reverse(red.begin(), red.end());
        reverse(blue.begin(), blue.end());

        if(rec.count(make_pair(blue, red)))
            cnt += rec[make_pair(blue, red)];

    }

    cout << cnt << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::string S;
    std::cin >> S;
    solve(N, S);
    return 0;
}
