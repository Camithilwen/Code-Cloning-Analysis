#include <iostream>
#include <vector>
//#define rep(i,n) for(int i = 0; i , (n); ++i)
using ll = long long;
using namespace std;

int sum(int n) {
    if (n == 0) {
        return 0;
    }

    int s = sum(n - 1);
    return s + n;
}
int main() {
    int N, W;
        cin >> N >> W;
        vector<vector<char>>A(N, vector<char>(W));
        
        for (int i = 0;i < N;i++) {
            for (int j = 0;j < W;j++) {
                cin >> A.at(i).at(j);
            }
        }
        bool hantei = true;
        for (int i = 0;i < N;i++) {
            for (int j = 0;j < W;j++){
                    if (j>0&&j<(W-1)&&i>0&&i<(N-1)&&A.at(i).at(j) == '#'&&A.at(i + 1).at(j) == '.' && A.at(i - 1).at(j) == '.' &&
                        A.at(i).at(j + 1) == '.' && A.at(i).at(j - 1) == '.') {
                         hantei=false;
                             break;
                    }
            }
            if (hantei == false) {
                break;
            }
        }
        if (hantei) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
}
