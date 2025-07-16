#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void pv(vector <int> &v) {
    for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}

void solve() {
	
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    vector <int> a(n, 0);
    vector <int> b(n, 0);
    
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    
    reverse(b.begin(),b.end());
    // pv(b);
    int prob = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] == b[i]) prob++;
    }
    int c = -1;
    int l = INT_MAX;
    int r = INT_MIN;
    for(int i = 0; i < n; i++) {
        if(a[i] == b[i]) {
            c = a[i];
            l = i;
            break;
        }
    }
    for(int i = n-1; i >= 0; i--) {
        if(a[i] == b[i]) {
            r = i;
            break;
        }
    }

    int toSwap = (r-l+1);
    if(toSwap == 0 || prob == 0) {
        cout << "Yes" << endl;
        pv(b);
        return 0;
    }
    int l0 = l;
    int r0 = r;
    int avail = 0;
    for(int i = 0; i < l; i++) {
        if(a[i] != c && b[i] != c) avail++;
    }
    for(int i = r+1; i < n; i++) {
        if(a[i] != c && b[i] != c) avail++;
    }
    if(avail < toSwap) {
        cout << "No" << endl;
        return 0;
    }
    else cout << "Yes" << endl;

    int i = 0;
    int j = r0+1;

    while(l <= r) {
        if(i < l0 && i < n) {
            if(a[i] != c && b[i] != c) {
                swap(b[i], b[l]);
                l++;
            }
        }
        i++;
        if(i == n) break;
    }
    // if(j < n) {
        while(l <= r) {
            if(j < n && a[j] != c && b[j] != c) {
                swap(b[j], b[l]);
                l++;
            }
            j++;
            // if(j == n) break;
        }
    // }


    // while(l <= r) {
    //     if(i < l0 && a[i] != c && b[i] != c) {
    //         swap(b[i], b[l]);
    //         l++;
    //         i++;
    //         continue;
    //     }
    //     else if(i == l0 && a[j] != c && b[j] != c && j < n) {
    //         swap(b[j], b[l]);
    //         l++;
    //         j++;
    //         continue;
    //     }
    //     i++;
    //     if(i == l0) j++;
    // }
    pv(b);
    


    
    return 0;
}