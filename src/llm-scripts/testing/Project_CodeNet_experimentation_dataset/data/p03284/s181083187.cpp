#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N,K;
    cin >> N >> K;
    if(N < K){
        cout << 1 << endl;
        return 0;
    }
    if(N%K == 0){
        cout << 0 << endl;
        return 0;
    }
    cout << N%K+1 - N%K << endl;
}

