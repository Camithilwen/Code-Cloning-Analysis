#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

struct RangeUpdateQuery{
    int n, now;
    std::vector<int> dat, time;

    void init(int n_){
        n = 1;
        now = 0;
        while(n < n_) n *= 2;
        dat.resize(2 * n - 1, std::numeric_limits<int>::max());
        time.resize(2 * n - 1, 0);
    }

    void update(int a, int b, int k, int l, int r, int x){
        if(r <= a || b <= l) return;
        if(a <= l && r <= b){
            dat[k] = x;
            time[k] = now;
        }
        else{
            update(a, b, k * 2 + 1, l, (l + r) / 2, x);
            update(a, b, k * 2 + 2, (l + r) / 2, r, x);
        }
    }

    void update(int a, int b, int x){
        now++;
        update(a, b, 0, 0, n, x);
    }

    int query(int k){
        k += n - 1;
        int res = dat[k], recent = time[k];
        while(k > 0) {
            k = (k - 1) / 2;
            if(recent < time[k]){
                recent = time[k];
                res = dat[k];
            }
        }
        return res;
    }
};


using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    RangeUpdateQuery ruq;
    ruq.init(n);
    while(q--){
        int com;
        cin >> com;
        if(com){
            int i;
            cin >> i;
            cout << ruq.query(i) << "\n";
        }else{
            int s, t, x;
            cin >> s >> t >> x;
            ruq.update(s, t + 1, x);
        }
    }
}
