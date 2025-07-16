#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
int main(void){
    long long N;
    cin >> N;
    long long A[N];
    long long count = 0;
    long long sum=0;
    long long ans ;
    for(int i=0;i<N;i++){
        cin >> A[i];
        if(A[i] < 0)count++;
        sum += abs(A[i]);
    }
    
    if(count % 2 == 0){
        ans = sum;
    }
    else{
        ans = 0;
        for(int i=0;i<N;i++){
            ans = max(ans,sum-abs(A[i])*2);
        }
    }
    cout << ans << endl;
}
