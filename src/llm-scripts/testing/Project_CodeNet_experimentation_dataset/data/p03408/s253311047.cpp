#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N;
    vector<string> blue(N);
    for(int i = 0; i < N; i++){
        cin >> blue.at(i);
    }
    cin >> M;
    vector<string> red(M);
    for(int i = 0; i < M; i++){
        cin >> red.at(i);
    }
    int ans = 0;
    int maxans = 0;
    for(int i = 0; i < N; i++){
        int bcnt = 1;
        int rcnt = 0;
        for(int j = 0; j < N; j++){
            if(i == j){
                continue;
            }
            if(blue.at(i) == blue.at(j)){
                bcnt++;
            }
        }
        for(int j = 0; j < M; j++){
            if(blue.at(i) == red.at(j)){
                rcnt--;
            }
        }
        ans = bcnt + rcnt;
        if(maxans < ans){
            maxans = ans;
        }
    }
    cout << maxans << endl;
}