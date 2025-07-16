#include <bits/stdc++.h>

using namespace std;

int main() {
    // blue input
    int n;
    cin >> n;
    vector<string> blue(n);
    for(int i = 0; i < n; i++) {
        cin >> blue.at(i);
    }
    // red input
    int m;
    cin >> m;
    vector<string> red(m);
    for(int i = 0; i < m; i++) {
        cin >> red.at(i);
    }

    int max = 0;

    for(int i = 0; i < n; i++) {
        string s = blue.at(i);
        int cnt = 0;
        for(int j = 0; j < n; j++) {
            if(s == blue.at(j)){
                cnt++;
            }
        }
        for(int k = 0; k < m; k++) {
            if(s == red.at(k)){
                cnt--;
            }
        }
        if(cnt >= max){
            max = cnt;
        }
    }

    cout << max << endl;

    return 0;
}