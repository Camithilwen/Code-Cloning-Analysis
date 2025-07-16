#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b;
    cin >> a >> b;
    
    int cnt = 0;
    for(int i = a; i <= b; i++){
        int l = i;
        vector<int> vec(5);
        rep(j, 5){
            vec[j] = l % 10;
            l /= 10;
        }
        if(vec[0] == vec[4] && vec[1] == vec[3]) cnt++;
    }
    
    cout << cnt << endl;
}