#include <iostream>
#include <string>

using namespace std;

const int MOD = 1000000007;

int solve(const string& s){
    const int N = s.size()/2;
    long long res = 1;
    int numS = 0, sumS = 0, inc = 0;
    for(auto& c : s){
        if(c == 'B'){
            if(inc%2 == 0){
                ++inc;
                ++numS;
                ++sumS;
            } else {
                if(numS == 0) return 0;
                --inc;
                res = (res * numS) % MOD;
                --numS;
            }
        } else {
            if(inc%2 == 0){
                if(numS == 0) return 0;
                --inc;
                res = (res * numS) % MOD;
                --numS;
            } else {
                ++inc;
                ++numS;
                ++sumS;
            }
        }
    }
    if(sumS != N) return 0;
    for(int i=1;i<=N;i++) res = (res*i)%MOD;
    return res;
}

int main(){
    int N;
    while(cin >> N){
        string s; cin >> s;
        cout << solve(s) << endl;
    }
}