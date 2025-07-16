#include <iostream>

using namespace std;

int main() {
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;

    for (int i = 0; i < ty-sy; i++)
        cout << 'U';
    for (int i = 0; i < tx-sx; i++)
        cout << 'R';
    for (int i = 0; i < ty-sy; i++)
        cout << 'D';
    for (int i = 0; i < tx-sx; i++)
        cout << 'L';
    cout << 'L';
    for (int i = 0; i <= ty-sy; i++)
        cout << 'U';
    for (int i = 0; i <= tx-sx; i++)
        cout << 'R';
    cout << 'D';
    cout << 'R';
    for (int i = 0; i <= ty-sy; i++)
        cout << 'D';
    for (int i = 0; i <= tx-sx; i++)
        cout << 'L';
    cout << 'U' << endl;
    return 0;
}