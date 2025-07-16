#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int N,K;
    cin >> N >> K;
    int l[N];
    for(int i = 0; i < N ;i++){
        cin >> l[i];
    }
    sort(l ,l+N ,greater<int>());
    int answer = 0;
    for(int i = 0; i < K ; i++){
        answer += l[i];
    }
    cout << answer << endl;
    return 0;
}