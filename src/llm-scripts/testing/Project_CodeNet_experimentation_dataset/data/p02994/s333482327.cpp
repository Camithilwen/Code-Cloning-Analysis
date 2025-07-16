#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
#define PI 3.14159265359
#define EPS 0.0000000001
#define MOD 1000000007
//cout << std::fixed << std::setprecision(15) << y << endl;


int main(){
    ll N, L;
    cin >> N >> L;

    if(L <= 0 && L + N - 1 > 0){
        cout << N * (L + L + N - 1) / 2 << endl;
    }else if(L + N - 1 <= 0){
        cout << (N - 1) * (L + L + N - 2) / 2 << endl;
    }else{
        cout << (N - 1) * (L + 1 + L + N - 1) / 2 << endl;
    }

    return 0;
}