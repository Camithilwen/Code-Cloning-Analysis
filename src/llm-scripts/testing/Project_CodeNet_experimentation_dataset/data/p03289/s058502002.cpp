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
    string S;
    cin >> S;

    bool check1 = false, check2 = false, check3 = true;
    ll Ccount = 0;
    if(S[0] == 'A'){
        check1 = true;
    }
    if(S[1] < 'a'){
        check3 = false;
    }
    for(ll i = 2; i < S.size() - 1; i++){
        if(S[i] == 'C' && Ccount == 0){
            check2 = true;
            Ccount++;
        }else if(S[i] < 'a'){
            check3 = false;
        }
    }
    if(S[S.size() - 1] < 'a'){
        check3 = false;
    }

    if(check1 && check2 && check3){
        cout << "AC" << endl;
    }else{
        cout << "WA" << endl;
    }

    return 0;
}