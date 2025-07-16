#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> D(10, 0);
    for(int i=0; i<K; i++) {
        int a;
        cin >> a;
        D[a] = 1;
    }

    for(int i=N; i<=100000; i++) {
        int num = i;
        bool flg = true;
        while(num) {
            int x = num % 10;
            if (D[x] == 1) {
                flg = false;
                break;
            }
            num /= 10;
        }
        if(flg && i>= N) {
            cout << i << endl;
            return 0;
        }
    }
}