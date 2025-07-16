#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,Y;
    cin >> N >> Y;

    int a10000 = -1, b5000 = -1, c1000 = -1;
    for(int a = 0; a <= N; a++){
        for(int b = 0; a + b <= N; b++){
            int c = N - a - b;
            int total = 10000*a + 5000*b + 1000*c;
            if(Y == total){
                a10000 = a;
                b5000 = b;
                c1000 = c;
            }
        }
    }
    cout << a10000 << " " << b5000 << " " << c1000 << endl;
}