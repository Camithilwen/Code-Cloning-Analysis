#include<bits/stdc++.h>
using namespace std;

int main(void) {
    long n, m;
    cin >> n >> m;
    vector<vector<long>> a(n, vector<long>(m));
    for(auto &l: a)
        for(auto &c: l)
            cin >> c, c--;

    long ok = 300, ng = 0;
    while(ok - ng > 1) {
        long mid = (ok+ng)/2;

        vector<long> idx(n);
        set<long> bad;

        while(1) {
            bool dame = false;

            for(long i=0; i<n; i++) {
                while(idx[i]<m && bad.count(a[i][idx[i]])) idx[i]++;
                if(idx[i] == m) {
                    dame = true;
                    break;
                }
            }
            if(dame) {
                ng = mid;
                break;
            }

            vector<long> cnt(m);
            for(long i=0; i<n; i++)
                cnt[a[i][idx[i]]]++;

            for(long i=0; i<m; i++)
                if(cnt[i] > mid)
                    bad.insert(i), dame = true;
            
            if(!dame) {
                ok = mid;
                break;
            }
        }
    }
    cout << ok << endl;
}
