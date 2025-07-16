#include <bits/stdc++.h>
using namespace std;

int main(void) {

    long long N,A,B;
    int i;
    long long sum = 0;

    scanf("%lld %lld %lld", &N, &A, &B);
    long long X[N];
    for(i=0;i<N;i++){
        scanf("%lld",&X[i]);
    }

    for(i=1;i<N;i++){
        long long dis = X[i] - X[i-1];
        if(B > dis * A){
            sum += dis * A;
        }
        else{
            sum += B;
        }
    }

    printf("%lld\n", sum);
}
