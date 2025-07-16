#include <bits/stdc++.h>
#include <climits>
#include <sstream>
using namespace std;

int main(){

    int K,T;
    cin >> K >> T;
    int A[T];
    int mx = 0;
    for(int i = 0;i < T;i++){
        cin >> A[i];
        mx = max(mx,A[i]);
    }
    
    cout << max(0,mx-1-(K-mx))<<endl;
}

