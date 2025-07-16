#include <iostream>
using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    int A[3];
    cin >> A[0] >> A[1] >>A[2];
    sort(A,A+3);
    if(A[0] == A[1] && A[1] == A[2]){
        fin("No");
    }else if ((A[0] != A[1] && A[1] != A[2]) ){
        fin("No");
    }else{
        fin("Yes");
    }
    
        return 0;
}