#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main(){
    LL N;
    cin >> N;
    
    int f = 10;

    for(LL A=1; A*A<=N; A++){

        if(N%A != 0) continue;

        LL a = A;
        LL b = N/A;
        int B_d = 0;
        int A_d = 0;

        while(a>0){
            a /= 10;
            A_d++;
        }

        while(b>0){
            b /= 10;
            B_d++;
        }

        f = min(f,max(A_d,B_d));
    }

    cout << f << endl;

}