#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    int N, Q;
    cin >> N >> Q;
    int Si, Ti, Xi, Di;
    vector<array<int, 3>> stx(N);
    for(int i=0;i<N;i++){
        cin >> Si >> Ti >> Xi;
        auto l = Si-Xi;
        auto r = Ti-Xi;
        if(l<0) l=0;
        stx[i] = array<int, 3>{l, r, Xi};
    }
    sort(stx.begin(), stx.end(), [](array<int, 3>& a, array<int, 3>& b){return a[2] < b[2];});
    set<int> D;
    map<int, int> res;
    for(int i=0;i<Q;i++){
        cin >> Di;
        D.insert(Di);
    }

    for(auto v : stx){
        auto itrl = D.lower_bound(v[0]);
        auto itrr = D.upper_bound(v[1]-1);
        for(auto itr = itrl; itr != itrr; ++itr){
            res[*itr] = v[2];
        }
        D.erase(itrl, itrr);
    }
    for(auto v : D){
        res[v] = -1;
    }
    for(auto m : res){
        cout << m.second << endl;
    }

    return 0;
}