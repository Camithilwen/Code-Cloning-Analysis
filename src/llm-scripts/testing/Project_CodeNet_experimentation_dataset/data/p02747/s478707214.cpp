#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#include <numeric>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[8]={ 0, 1, 0,-1, 1, 1,-1,-1}; // x軸方向への変位
ll dy[8]={ 1, 0,-1, 0, 1,-1, 1,-1}; // y軸方向への変位

int main(void) {
    string s;
    cin >> s;
    bool ok = true;
    for(ll i = 0; i < s.length(); i+=2){
        if(s[i]!='h'||s[i+1]!='i'){
            ok = false;
            break;
        }
    }
    if(ok==true)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
