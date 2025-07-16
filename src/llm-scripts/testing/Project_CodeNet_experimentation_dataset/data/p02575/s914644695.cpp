#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)

template <typename T>
struct RUQ //calculateはminimum
{
    int n;
    const T ex = 1 << 30; //dat 初期値(minなので)
    const T em = 1 << 30; //lazy 初期値(minなので)
    vector<T> dat, lazy; //tree本体
    RUQ(vector<T> v){
        int x = 1;
        int i;
        n = v.size();
        while(x < n) x <<= 1;
        n = x; 
        dat.resize(2*n-1, ex);
        lazy.resize(2*n-1, em);
        for(i = 0;i < v.size();++i){
            dat[i + n - 1] = v[i];
        }
        for(i = n-2;i >= 0;--i){
            dat[i] = calculate(dat[2*i+1], dat[2*i+2]);
        }
    }
    
    T calculate(T a, T b){
        return min(a, b); //minで使う
    }
    
    void eval(int now){
        if(lazy[now] == em) return;
        if(now < n - 1){ //最小値なのでそのまま代入
            lazy[2*now + 1] = lazy[now];
            lazy[2*now + 2] = lazy[now];
        }
        dat[now] = lazy[now];
        lazy[now] = em;
    }
    
    void update(int a, int b, T x, int now, int l, int r){
        eval(now);
        if(a <= l && r<= b){
            lazy[now] = x; //上から書き換える。最小値なので代入する
            eval(now);
        }else if(a < r && l < b){
            update(a, b, x, 2*now + 1, l, (l + r)/2);
            update(a, b, x, 2*now + 2, (l + r)/2, r);
            dat[now] = calculate(dat[2*now + 1], dat[2*now + 2]);
        }
    }
    void update(int a, int b, T x){update(a, b, x, 0, 0, n);}
    
    T query(int a, int b){return query_sub(a, b, 0, 0, n);}
    T query_sub(int a, int b, int now, int l, int r){
        eval(now);
        if(r <= a || b <= l) return ex;
        else if(a <= l && r <= b) return dat[now];
        else{
            T vl = query_sub(a, b, 2*now + 1, l, (l + r)/2);
            T vr = query_sub(a, b, 2*now + 2, (l + r)/2, r);
            return calculate(vl, vr);
        }
    }
    
    inline T operator[](int a) { return query(a, a + 1); }
    void print() {
        for (int i = 0; i < 2 * n - 1; ++i) {
            cout << (*this)[i];
            if (i != n) cout << ",";
        }
        cout << endl;
    }
};

int main()
{
    cin.tie(0); ios::sync_with_stdio(false); 
    int i;
    int h,w;
    cin >> h >> w;
    vector<int> v(w, 0);
    const int INF = 1e9;
    set<int> st;
    rep(i,w) st.insert(i);
    RUQ<int> ruq(v);
    rep(i,h){
        int a,b;
        cin >> a >> b;
        --a;    --b;
        auto x = st.lower_bound(a);
        auto y = st.upper_bound(b);
        if(x == y){
            ruq.update(a, b+1, INF);

            int ans = ruq.query(0, w);

            if(ans == INF) cout << -1 << endl;
            else cout << ans + i + 1 << endl;
        }else if(b+1 == w){
            st.erase(x, y);
            ruq.update(a, b+1, INF);

            int ans = ruq.query(0, w);

            if(ans == INF) cout << -1 << endl;
            else cout << ans + i + 1 << endl;
        }else{
            auto it = prev(y);
            int ind = *it;
            st.erase(x, y);
            st.insert(b+1);
            int tmp = ruq.query(ind, ind+1) + (b + 1 - ind);
            ruq.update(b+1, b+2, min(tmp, ruq.query(b+1, b+2)));
            ruq.update(a, b+1, INF);

            int ans = ruq.query(0, w);

            if(ans == INF) cout << -1 << endl;
            else cout << ans + i + 1 << endl;
        }
    }

    return 0;
}
