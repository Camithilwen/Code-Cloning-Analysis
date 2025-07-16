#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, x;
    cin >> N >> x;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());
    int ans = 0;
    for(int i = 0; i < N; i++){
        x -= A.at(i);
        if(x < 0){
            break;
        }
        ans++;
    }
    if(x > 0){
        ans--;
    }
    cout << ans << endl;
    return 0; 
}