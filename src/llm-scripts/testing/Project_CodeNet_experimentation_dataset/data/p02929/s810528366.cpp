#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <utility>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <climits>
#include <set>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;
const long long MOD = 1000000007;
int main(){
    int N;
    string S;
    cin >> N;
    cin >> S;
    
    int current_open = 0;
    long long N_fact = 1;
    for(int i = 1; i <= N; i++){
        N_fact = (N_fact * i) % MOD;
    }
    
    long long ans = 1;
    for(int i = 0; i < S.size(); i++){
        if(S[i] == 'B'){
            if(current_open % 2 == 0){
                current_open ++;
            } else {
                ans = (ans * current_open) % MOD;
                current_open --;
            }
        } else {
            if(current_open % 2 == 0){
                if(current_open <= 0){
                    ans = 0;
                    break;
                } else {
                    ans = (ans * current_open) % MOD;
                    current_open --;
                }
            } else {
                current_open ++;
            }
        }
    }
    
    ans = (ans * N_fact) % MOD;

    if(current_open != 0){
        cout << 0 << endl;
    } else {
        cout << ans << endl;
    }
}