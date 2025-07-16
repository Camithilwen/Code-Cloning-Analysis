#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

vector<long long> create_table(vector<long long> pattern) {
    vector<long long> table(pattern.size()+1, 0);
    
    long long j = 0;
    for (long long i = 1; i < pattern.size(); i++) {
        if (pattern[i] == pattern[j])
            table[i] = j++;
        else {
            table[i] = j;
            j = 0;
        }
    }
    table[pattern.size()] = j;
    
    return table;
}

vector<long long> kmp_search(vector<long long> target, vector<long long> pattern) {
    vector<long long> table = create_table(pattern);
    /*
    for (int i = 0; i < table.size(); i++)
        cout << table[i] << " ";
    cout << endl;
    */
    
    vector<long long> result;
    long long p = 0;
    for (long long i = 0; i < target.size(); i++) {
        if (target[i] == pattern[p])
            p++;
        else if (p != 0 && target[i] != pattern[p]) {
            p = table[p];
            i--;
        }
        //cout << i << " " << p << endl;
        
        if (p == pattern.size()) {
            result.push_back((i+1)-p);
            p = table[p];
        }
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    
    vector<ll> copy_a(a);
    copy_a.insert(copy_a.end(), a.begin(), a.end()-1);
    vector<ll> new_a(2*n-2), new_b(n-1);
    rep(i, 2*n-2) new_a[i] = copy_a[i] ^ copy_a[i+1];
    rep(i, n-1) new_b[i] = b[i] ^ b[i+1];
    
    vector<ll> kmp = kmp_search(new_a, new_b);
    rep(i, kmp.size())
        cout << kmp[i] << " " << (a[kmp[i]] ^ b[0]) << endl;
}