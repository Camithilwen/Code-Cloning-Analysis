#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, X, T;
    cin >> N >> X >> T;
    
    int minute = 0;
    
    while(N > 0){
        minute += T;
        N -= X;
    }

    cout << minute << endl;
}