#include <bits/stdc++.h>
using namespace std;
#define     LL              long long int
#define     FOR(I,A,B)      for( int I = A; I < B; ++I )
#define     SFI(X)          scanf("%d",&X)
#define     SFL(X)          scanf("%lld",&X)


int main() {

//    SAT, SUN, MON, TUE, WED, THU, FRI
//    1     2    3    4    5    6    7

    string S;

    cin >> S;

    if(S == "MON") {
            printf("6\n");
    } else if(S == "TUE") {
                printf("5\n");
    } else if(S == "WED") {
                printf("4\n");
    } else if(S == "THU") {
                printf("3\n");
    } else if(S == "FRI") {
                printf("2\n");
    } else if(S == "SAT") {
        printf("1\n");
    }else {
        printf("7\n");
    }
    
    return 0;
}
