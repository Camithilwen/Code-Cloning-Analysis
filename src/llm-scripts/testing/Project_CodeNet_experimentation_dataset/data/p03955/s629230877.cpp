#include <iostream>
using namespace std;

const int MAX_N = 100005;

int n, A[MAX_N], B[MAX_N], C[MAX_N], pos[3 * MAX_N], rev[3 * MAX_N];


void wypisz() {
    cout << "----------------------\n";
    for(int i = 1; i <= n; i++) cout << A[i] << " ";
    cout << endl;
    for(int i = 1; i <= n; i++) cout << B[i] << " ";
    cout << endl;
    for(int i = 1; i <= n; i++) cout << C[i] << " ";
    cout << endl;
}

void swapColumn(int i) {
    swap(A[i], C[i]);
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> A[i];
    for(int i = 1; i <= n; i++) cin >> B[i];
    for(int i = 1; i <= n; i++) cin >> C[i];
    
    for(int i = 1; i <= n; i++) {
        if((B[i] % 3 != 2) || (((B[i] - 2) / 3) % 2 == i % 2)) {
            cout << "No";
            return 0;
        }
        int a = (A[i] - 1) / 3;
        int b = (B[i] - 1) / 3;
        int c = (C[i] - 1) / 3;
        if(a != b || a != c || b != c) {
            cout << "No";
            return 0;
        }
    }
    for(int i = 1; i <= n; i++) {
        pos[B[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        if(B[i] == 3 * i - 1) {
            continue;
        }
        int j = pos[3 * i - 1];
        int x = B[i];
        int y = B[j];
        B[i] = y;
        B[j] = x;
        swap(A[i], A[j]);
        swap(C[i], C[j]);
        pos[x] = j;
        pos[y] = i;
        
        if((i - j) % 4 != 0) {
            swapColumn(i);
            swapColumn(j);
        }
        swap(A[i + 1], C[i + 1]);
//         wypisz();
    }
    
    int odd = 0, even = 0;
    for(int i = 1; i <= n; i++) {
//         if(rev[B[i]]) swap(A[i], C[i]);
        if(A[i] > C[i]) {
            if(i % 2 == 1) odd++;
            else even++;
//             cout << "No3";
//             return 0;
        }
    }
    
    if(odd % 2 == 1 || even % 2 == 1) {
        cout << "No";
        return 0;
    }
    
    cout << "Yes";
    return 0;
}