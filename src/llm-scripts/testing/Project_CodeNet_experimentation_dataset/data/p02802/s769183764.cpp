#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    
    vector<bool> IsCorrect(N, false);
    vector<int> Penalties(N, 0);

    for(int i=0; i<M; i++){
        int p;
        string s;
        cin >> p >> s;
        
        p=p-1;
        if(s=="AC"){
           IsCorrect[p] = true; 
        }

        if(s=="WA" && IsCorrect[p]==false){
            Penalties[p] += 1;
        }

    }


    int c_ans = 0;
    int c_pena = 0;
    for(int i=0; i<N; i++){
        if(IsCorrect[i]== true){
            c_ans++;
            c_pena += Penalties[i];
        }
    }
    cout << c_ans << " " << c_pena << endl;
    return 0;
}