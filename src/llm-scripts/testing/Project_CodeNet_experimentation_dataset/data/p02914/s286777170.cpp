#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll maxSubarrayXOR(ll a[], int n) {
    int index = 0;
    for(int i = 60; i >= 0; i--) {
        int pos = index;
        int f = 0;
        for(int j = index; j < n; j++) {
            if(a[j] & (1LL << i)) f = 1, pos = j;
        }
        if(!f) continue;
        swap(a[index], a[pos]);
        for(int j = 0; j < n; j++) {
            if(j != index && (a[j] & (1LL << i))) a[j] ^= a[index];
        }
        index++;
    }
    ll res = 0;
    for(int i = 0; i < n; i++) res ^= a[i];
    return res;
}

int n;
ll a[100010], ans = 0;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%lld", a+i);
        ans ^= a[i];
    }
    for(int i = 0; i < n; i++) a[i] &= ~ans;
    cout << ans + 2*maxSubarrayXOR(a, n);
}