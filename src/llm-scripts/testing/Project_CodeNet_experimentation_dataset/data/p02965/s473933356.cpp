#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long fact[3000005];

long long powmod(long long a, long long b){
    long long x = 1;
    long long y = a;
    while(b){
        if(b&1){ x = (x*y)%MOD; }
        y = (y*y)%MOD;
        b >>= 1;
    }
    return x;
}

inline long long ncr(long long a, long long b){
    return fact[a]*powmod((fact[a-b]*fact[b])%MOD, MOD-2)%MOD;
}

long long solve(int N, int sum, int k){
    // exactly N non-negative integers
    // the sum is the variable sum
    // exactly k odd
    if((sum-k)&1){return 0;}
    if(sum-k<0){return 0;}

    // Let's make the k odd integers non-negative even integers
    // Then, the sum becomes (sum-k) and we can then divide by 2 to normalise the non-negative integers
    // The integers can now be any non-negative integer, without any other restriction, so formula can be used.
    // (((sum-k)/2)+(N-1)) choose (N-1) ways to make such integers

    // Don't forget that there are N choose k ways to arrange the odd integers.
    return ncr(N, k)*ncr( ((sum-k)>>1)+(N-1) , N-1)%MOD;
}

int main(){
    int N, M;
    scanf("%d%d", &N, &M);

    fact[0] = 1;
    for(int i = 1; i <= 3000004; i ++){
        fact[i] = (fact[i-1]*i)%MOD;
    }

    // Let us ignore the maximum integer rule and count the number of ways
    // There can only be at most M odd integers.
    long long temp1 = 0;
    for(int k = 0; k <= min(M, N); k ++){
        temp1 += solve(N, 3*M, k);
        //printf("solve(%d, %d, %d)=%lld\n", N, 3*M, k, solve(N, 3*M, k));
    }
    temp1 %= MOD;

    // Notice that the maximum integer cannot exceed 2M. There can only be a maximum of one violation
    // because 2M+2M = 4M > 3M, a contradiction. Hence, there are N ways to choose the violating integer.
    // Then, we can subtract 2M from the offending integer. 2M is even, hence there is no effect on parity.
    // Conditions remain the same as before, except that the offending integer must be positive.
    long long temp2 = 0;
    for(int k = 0; k <= min(M, N); k ++){
        temp2 += solve(N, M, k);
    }
    temp2 %= MOD;
    temp2=temp2*N%MOD;

    // Now, we count number of ways such that the offending integer is 0 because we have over-subtracted those cases.
    // There are only N-1 integers left since the offending integer can be removed, and that the number of odd
    // integers would remain the same since M is even.
    long long temp3 = 0;
    for(int k = 0; k <= min(M, N-1); k ++){
        temp3 += solve(N-1, M, k);
    }
    temp3 %= MOD;
    temp3=temp3*N%MOD;

    //printf("temp1=%lld temp2=%lld temp3=%lld\n", temp1, temp2, temp3);

    long long ans = (temp1-temp2+temp3+MOD*3)%MOD;
    printf("%lld", ans);
    return 0;
}
