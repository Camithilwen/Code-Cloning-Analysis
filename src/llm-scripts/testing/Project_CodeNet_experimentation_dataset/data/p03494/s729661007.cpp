#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N, A;
    cin >> N;
    int times = 0;
    int answer = 30;
    
    for (int i=0; i < N; i++) {
        cin >> A;
        
        while (A % 2 == 0) {
            times +=1;
            A /=2;
        }
        
        if (times <= answer) answer = times;
        
        times = 0;
    }
    
    cout << answer << endl;
}