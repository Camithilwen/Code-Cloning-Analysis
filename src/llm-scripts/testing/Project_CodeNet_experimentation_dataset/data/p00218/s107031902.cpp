#include<bits/stdc++.h>
#define REP(i,n) for(long long i=0;i<n;++i)
#define FOR(i,a,b) for(long long i=a;i<b;++i)
using namespace std;
using point = pair< int,int >;
using ll = long long;

int main(){
    int n;
    int m, e, j;
    bool hund;
    while (~scanf("%d", &n)) {
        REP(i, n) {
            hund = false;
            scanf("%d%d%d", &m, &e, &j);
            if (m == 100 || e == 100 || j == 100) hund = true;
            if (hund || (m + e) / 2 >= 90 || (m + e + j) / 3 >= 80) {
                puts("A");
            } else if ((m + e + j) / 3 >= 70 || (m + e + j) / 3 >= 50 && (m >= 80 || e >= 80)) {
                puts("B");
            } else {
                puts("C");
            }
        }
    }

    return 0;
}


