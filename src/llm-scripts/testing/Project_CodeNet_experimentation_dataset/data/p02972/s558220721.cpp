#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> a(N + 1);
    for(int i = 1; i < N + 1; i++) cin >> a[i];
    vector<int> ko(N + 1, 0);
    int cnt = 0;
    for(int i = N; i > 0; i--){
        int t = 0;
        for(int j = i; j <= N; j += i){
            t += ko[j];
        }
        if(t % 2 != a[i]) {
            ko[i]++;
            cnt++;
        }
    }
    cout << cnt << endl;
    for(int i = 1; i <= N; i++){
        if(ko[i] == 1){
            cout << i << endl;
        }
    }
}