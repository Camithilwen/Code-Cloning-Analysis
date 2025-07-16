#include<bits/stdc++.h>
#include<boost/dynamic_bitset.hpp>
using namespace std;
using u64 = uint64_t;
using s64 = int64_t;

int main(void) {
    u64 N, M;
    cin >> N >> M;

    u64 lM = M / 2;
    u64 lN = N / 2;
    u64 rM = M - lM;
    u64 rN = N - lN;

    if(lN == rN) {
        lN--;
    }

    for(u64 i=0, l=1, r=lN; i<lM; i++, l++, r--) {
        cout << l << " " << r << endl;
    }

    for(u64 i=0, l=N/2+1, r=N; i<rM; i++, l++, r--) {
        cout << l << " " << r << endl;
    }
    
    return 0;
}