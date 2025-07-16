#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int N = 0, M = 0;
int points[1001];
int scores[1002001];

bool check(int a, int c){
    if(a >= (N + 2) * (N + 1) / 2 - 1){
        return true;
    }
    return (scores[a] <= c && scores[a + 1] > c);
}

int search2(int a, int b, int c){
    int pib = a + b - b / 2;
    if(check(pib, c)){
        return pib;
    }else if(scores[pib] < c){
        return search2(pib, b / 2, c);
    }else{
        return search2(a, b / 2, c);
    }
}

int main(){
    for(;;){
        for(int i = 0; i < 1001; i++){
            points[i] = 0;
        }
        for(int i = 0; i < 1002001; i++){
            scores[i] = 0;
        }
        if(cin >> N){
            if(N == 0){
                break;
            }
            cin >> M;
            for(int i = 1; i <= N; i++){
                cin >> points[i];
            }
            for(int i = 0; i <= N; i++){
                for(int j = i; j <= N; j++){
                    scores[(2 * N - i + 1) * i / 2 + j] = points[i] + points[j];
                }
            }
            int mxsco = 0;
            sort(scores, scores + ((N + 2) * (N + 1)) / 2);
            for(int i = 0; i < (N + 2) * (N + 1) / 2; i++){
                if(scores[i] > M){
                    break;
                }
                int nosco = scores[i] + scores[search2(0, (N + 2) * (N + 1) / 2, M - scores[i])];
                if(nosco >= mxsco &&  nosco <= M){
                    mxsco = nosco;
                }
            }
            cout << mxsco << endl;
        }else{
            break;
        }
    }
    return 0;
}