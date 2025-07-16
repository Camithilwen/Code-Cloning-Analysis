#include <bits//stdc++.h>
using namespace std;
#define int long long
signed main() {
    int A,N,Max=0;
    cin >> N;
    long long goukei=0;
    for(int i=0;i<N;i++){
        cin >> A;
        goukei+=max(Max-A,(int)0);
        Max=max(A,Max);
    }
    cout << goukei << endl;
    
}

