#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> num(N, -1);
    for (int i=0; i<M; i++) {
        int si, ci;
        cin >> si >> ci;
        si--;
        if ((num[si] != -1) && (num[si] != ci)){
            cout << -1;
            return 0;
        }
        num[si] = ci;
    }
    if (N == 1) {
        if (num[0] == -1) {
            cout << 0;
            return 0;
        } else {
            cout << num[0];
            return 0;
        }
    } else {
        for (int j=0; j<N; j++){
            if (j == 0 && num[j] == 0) {
                cout << -1;
                return 0;
            }
            if (j == 0 && (num[j] == -1)){
                num[j] = 1;
            }

            if (num[j] == -1) {
                num[j] = 0;
            }
        }
    }



    // // bool first_val = true;
    // for (int j=0; j<N; j++) {
    //     if ((j == 0) && (num[j] == 0) && (N != 1)){
    //         cout << -1;
    //         return 0;
    //     } else if ((j == 0) && (num[j]==-1)) {
    //         num[j] = 1;
    //     }

    //     // if (num[j] != -1) first_val = false;
    //     // if ((j==0) && (num[j] == -1)) num[j] = 1;
    //     if (num[j] == -1){
    //         num[j] = 0;
    //     }
    // }

    int ans = 0;
    for (int k=0; k<N;k++) {
        ans = ans * 10 + num[k];
    }
    cout << ans << endl;
}