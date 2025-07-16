#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

void printDP(vvi &dp){
    for(auto v: dp){
        for(auto x: v){
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void inc(bitset<15> &a){
    a = a.to_ullong() +1;
}

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> testimonies(n);
    vvi dp(n,vi(n,-1));
    for(int i = 0 ; i < n ; i ++ ){
        int q;
        cin >> q;
        vector<pair<int,int>> xy(q);
        for(int j = 0 ; j < q;j++){
            int f,s;
            cin >> f>> s;
            f--;

            xy[j] = {f,s};
            dp[f][i] = s;
        }
        testimonies[i]  = xy;
    }

//    printDP(dp);
    bitset<15> bp;
    int maxScore = 0;
    while (bp.count() < n){
        inc(bp);
        bool isValid = true;
        for(int i = 0 ; i <n;i++ ){
            isValid = true;
            if(bp[i]){
                for(int j = 0 ; j < n ; j++){
                    if(dp[i][j] == 0 && bp[j]){
                        isValid = false;
                        break;
                    }
                }
            }else{
                for(int j = 0 ; j < n ; j++){
                    if(dp[i][j] == 1 && bp[j]){
                        isValid = false;
                        break;
                    }
                }
            }
            if(!isValid){
                break;
            }
        }
        if(isValid){
            maxScore = max(maxScore,(int)bp.count());
        }
    }
    cout << maxScore;
    return 0;
}

