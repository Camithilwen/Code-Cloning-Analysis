#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<long long int, long long int> P;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

long long int DP[110000] = {}, DP2[110000] = {};

long long int pow_m1(long long int num){
	long long int pow_num = MOD - 2;
	long long int mod_num = MOD;
	long long int pow_cur = num;
	long long int ret = 1;
	while(pow_num > 0){
		if(pow_num % 2 == 1){
			ret *= pow_cur;
			ret %= mod_num;
		}
		pow_cur *= pow_cur;
		pow_cur %= mod_num;
		pow_num /= 2;
	}
	return ret;
}

int main(){
	long long int N, X;
	cin >> N >> X;
    long long int S[300];
	for(int i = 0; i < N; i++){
		cin >> S[i];
	}
    sort(S, S + N);
    long long int num = 1;
    for(int i = 1; i <= N; i++){
        num *= i;
        num %= MOD;
    }
    DP[X] = num;
    for(int i = N - 1; i >= 0; i--){
        num = pow_m1(i + 1);
        for(int j = 0; j <= X; j++){
            DP2[j] = 0;
        }
        for(int j = 0; j <= X; j++){
            DP2[j % S[i]] += DP[j] * num;
            DP2[j % S[i]] %= MOD;
            DP2[j] += DP[j] * (num * i % MOD);
            DP2[j] %= MOD;
        }
        for(int j = 0; j <= X; j++){
            DP[j] = DP2[j];
        }
    }
    long long int ans = 0;
    for(int i = 1; i <= X; i++){
        ans += i * DP[i];
        ans %= MOD;
    }
    cout << ans << endl;
}