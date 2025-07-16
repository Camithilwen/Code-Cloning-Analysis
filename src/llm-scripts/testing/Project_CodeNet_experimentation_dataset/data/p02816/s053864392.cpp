#include<iostream>
using namespace std;
const int BUF = 2000005;
const int MOD = 1000000007;


int add(int a, int b) {
    return (a + b) % MOD;
}

int sub(int a, int b) {
    return (a - b + MOD) % MOD;
}

int mul(int a, int b) {
    return 1LL * a * b % MOD;
}


int nNum;
int a[BUF], b[BUF];

void read() {
    cin >> nNum;
    for (int i = 0; i < nNum; ++i) cin >> a[i];
    for (int i = 0; i < nNum; ++i) cin >> b[i];
}


void work() {
    static int s[BUF];
    static int t[BUF];
    for (int i = 0; i < nNum; ++i) {
        s[i] = a[i] ^ a[(i + 1) % nNum];
        t[i] = b[i] ^ b[(i + 1) % nNum];
    }

    const int P = 1<<30;

    int sHash = 0;
    int tHash = 0;
    for (int i = 0; i < nNum; ++i) {
        sHash = add(mul(sHash, P), s[i]);
        tHash = add(mul(tHash, P), t[i]);
    }
    
    int pPowNNum = 1;
    for (int i = 0; i < nNum - 1; ++i) {
        pPowNNum = mul(pPowNNum, P);
    }
    
    for (int shift = 0; shift < nNum; ++shift) {
        if (sHash == tHash) {
            cout << shift << ' ' << (a[shift] ^ b[0]) << endl;
        }
        sHash = sub(sHash, mul(s[shift], pPowNNum));
        sHash = mul(sHash, P);
        sHash = add(sHash, s[shift]);
    }
}


int main() {
    read();
    work();
    return 0;
}
