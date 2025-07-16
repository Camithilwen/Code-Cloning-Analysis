#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<29;
using namespace std;
using ll = long long;
int main(){
    int N , sum = 0;
    string S;
    cin >> N >> S;
    for(int i = 0; i < N; i++){
        if(S[i] == 'E'){
            sum++;
        }
    }
    int t = sum;
    for(int i = 0; i < N; i++){
        if(S[i] == 'E'){
            sum--;
        }
        if(S[i] == 'W'){
            sum++;
        }
        t = min(t , sum);
    }
    cout << t << endl;
}
