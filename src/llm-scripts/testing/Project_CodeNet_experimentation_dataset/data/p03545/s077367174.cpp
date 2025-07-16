#define _USE_MATH_DEFINES  // M_PI等のフラグ

#include <iostream>
#include <bitset>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <list>

#define MOD 1000000007
#define COUNTOF(array) (sizeof(array)/sizeof(array[0]))

using namespace std;


void solve(){
    string s;
    cin >> s;

    for (int bit=0; bit<(1<<3); bit++) {
        string ans = s.substr(0,1);
        int result = s.at(0) - '0';

        for (int i=0; i<3; i++) {
            if (bit>>i&1) {
                // iビット目が1なら+演算する
                result += s.at(i+1)-'0';
                ans += "+";
            }
            else {
                // iビット目が0なら-演算する
                result -= s.at(i+1)-'0';
                ans += "-";
            }
            ans.push_back(s.at(i+1));
        }

        if (result == 7) {
            cout << ans << "=7" << endl;
            return;
        }
    }
}

int main(int argc, char const *argv[]){
    solve();
    return 0;
}