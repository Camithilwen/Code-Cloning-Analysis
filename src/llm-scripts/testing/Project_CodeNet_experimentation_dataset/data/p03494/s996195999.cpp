#include <iostream>
#include <string.h>
using namespace std;

int main() {

    int N;
    int cnt = 0;

    cin >> N;

    int a[N];
    int a_next[N];

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        a[i] = tmp;
    }

    do {
        int flg = 0;
        for (int i = 0; i < N; i++) {
            if (a[i] % 2 == 0){
                a_next[i] = a[i] / 2;
            }
            else{
                flg = 1;
                break;
            }
        }

        if (flg == 0){
            cnt = cnt + 1;
            for (int j = 0; j < N; j++) {
                a[j] = a_next[j] ;
            }
        }
        else{
            cout << cnt << endl;
            return 0;
        }

    } while (true);

    return 0;

}