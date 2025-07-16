#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N, X, T, time;
    cin >> N >> X >> T;
    time = N/X;
    
    if (N%X != 0) time += 1;
    
    cout << time*T << endl;
}
