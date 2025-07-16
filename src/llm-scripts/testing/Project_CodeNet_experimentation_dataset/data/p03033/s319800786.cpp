#include<bits/stdc++.h>

using namespace std;
using ll = long long;

inline int Calcu(int a,int b){
    return min(a, b);
}

class SegTree{
    public:
        int n;
        int g;
        std::vector<int> data;

        SegTree(std::vector<int> a, int _g){
            g = _g;
            for (n = 1; n < (int) a.size(); n *= 2);
            data.resize(n * 2, g);
            //for (int i = 0; i < (int) a.size(); i++) data[i + n] = a[i];
            //for (int i = n - 1; i >= 1; i--)
            //    data[i] = min(data[i], Calcu(data[i * 2], data[i * 2 + 1]));
        }

        int rec(int l, int r, int node, int node_l, int node_r, int val) {
            if (node_r <= l || node_l >= r) return g;
            if (node_l >= l && node_r <= r) return data[node] = min(data[node], val);
            int mid = (node_l + node_r) / 2;
            return Calcu(
                rec(l, r, node * 2, node_l, mid, val),
                rec(l, r, node * 2 + 1, mid, node_r,val));
        }

        void query(int l,int r, int val){
            rec(l,r,1,0,n,val);
        }

        int get(int index){
            int res = data[index += n];
            for(;index /= 2;)
                res = min(res, data[index]);
            return res;
        }
};


int main()
{
    int n, q; cin >> n >> q;
    vector<tuple<int,int,int>> p(n);
    vector<int> c(q);
    for(int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        a -= c;
        b -= c;
        p[i] = tie(a, b, c);
    }
    for(int i = 0; i < q; i++)cin >> c[i];
    map<int,int> mp;
    for(int i = 0; i < n; i++)mp[get<0>(p[i])] = -1, mp[get<1>(p[i])] = -1;
    for(int i = 0; i < q; i++)mp[c[i]] = -1;

    int za = 0;
    for(auto &i : mp)i.second = za++;

    for(int i = 0; i < n; i++)get<0>(p[i]) = mp[get<0>(p[i])], get<1>(p[i]) = mp[get<1>(p[i])];
    for(int i = 0; i < q; i++)c[i] = mp[c[i]];

    const int INF = 2e9;
    SegTree tree(vector<int>(za), INF);
    for(int i = 0; i < n; i++) {
        int a, b, c; tie(a, b, c) = p[i];
        tree.query(a, b, c);
    }

    for(int i = 0; i < q; i++) {
        cout << (tree.get(c[i]) == INF ? -1 : tree.get(c[i])) << endl;
    }

}