#include <iostream>
#include <cstring>
using namespace std;
char a[4005];
int main() {
    int N, cnt = 0;
    long long sum = 0;
    cin >> N >> a;
    for(int i = 0; i < N; i++)
        if(a[i] == 'B')
            cnt ++;
    for(int i = 0; i < N; i++)
        if(a[i] != 'R')
            continue;
        else for(int j = 0; j < N; j++) {
            if(j == i || a[j] != 'G')
                continue;
            else if(i < j) {
                sum += cnt - (2 * i - j  > 0 && a[2 * i - j] == 'B') - (2 * j - i  < N && a[2 * j - i] == 'B');
                if(i != j - 1)
                    sum -= ((i + j) % 2 == 0 && a[(i + j) / 2] == 'B');
            } else if(i > j) {
                sum += cnt - (2 * j - i  > 0 && a[2 * j - i] == 'B') - (2 * i - j  < N && a[2 * i - j] == 'B');
                if(i != j + 1)
                    sum -= ((i + j) % 2 == 0 && a[(i + j) / 2] == 'B');
            }
           // cout << i << " " << j << " " << sum << endl;
        }
    cout << sum << endl;
}