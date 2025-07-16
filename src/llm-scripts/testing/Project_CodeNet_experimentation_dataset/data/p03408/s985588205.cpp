#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    int count = 0;
    int score = 0;
    cin >> N;
    vector<string> s(N);
    for(int i=0;i<N;i++){
        cin >> s.at(i);
    }
    cin >> M;
    vector<string> t(M);
    for(int i=0;i<M;i++){
        cin >> t.at(i);
    }
    for(int i=0;i<N;i++){
        count = 0;
        for(int j=0;j<N;j++){
            if(s.at(i) == s.at(j)) count++;
        }
        for(int j=0;j<M;j++){
            if(s.at(i) == t.at(j)) count--;
        }
        score = max(score,count);
    }
    cout << score << endl;


}