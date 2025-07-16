#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N,X;
    cin >> N >> X;
    vector<long long> A(N);
    for(int i = 0; i < N;i++)cin >> A[i];
    long long ans = 0;
    long long b = 0;
    for(int i =1; i < N;i++){
       b = max(0LL,A[i-1]+A[i]-X);
       ans += b;
       A[i]= max(0LL,A[i]-b);
    }
    cout << ans << endl;
    
    
}
