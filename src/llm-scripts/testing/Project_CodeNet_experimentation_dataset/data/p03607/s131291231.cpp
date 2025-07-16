#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());
    long long temp = 0, ans = 0;;
    long long i = 0, num;
    while(i < N){
        temp = 0;
        num = A.at(i);
        while(i < N && A.at(i) == num){
            temp++;
            i++;
        }
        if(temp % 2 == 1){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}