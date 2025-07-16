#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC
#define debug(x) std::cout << #x << ": " << x << '\n';

const int N = 1e5+7;
int a[3][N];
int col[N * 3];

struct Fen {
int f[N];
void clear() {
    for (int i = 0; i < N; ++i) f[i] = 0;
}   
void add(int i, int x) {
    for (; i < N; i |= i + 1) 
        f[i] += x;
}   
int get(int i) {
    int ans = 0;
    for (; i >= 0; i &= i + 1, --i) ans += f[i];
    return ans;
}   
int get(int l, int r) {
    //check r < l!
    return get(r) - get(l - 1);
}   
} f;

signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(20); 
    #endif

    auto get = [&] (vector <int> a) {
        reverse(all(a));

        f.clear();

        int ans = 0;
        for (auto e : a) {
            ans += f.get(e);
            f.add(e, 1);
        }   
        return ans & 1;
    };  

    int n;
    cin >> n;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            col[a[i][j]] = j;
        }

    int x = 1; 
    vector <int> inv(2);
    vector <int> p[2];
    for (int i = 0; i < n; ++i) {

        int c = col[x];

        vector <int> t;
        for (int j = 0; j < 3; ++j)
            t.app(a[j][c]);        

        auto t1 = t;
        sort(all(t1));
        vector <int> w = {x, x + 1, x + 2};
        if (t1 != w) {
            cout << "No" << endl;
            exit(0);
        }   
        if (t[1] != x + 1) {
            cout << "No" << endl;
            exit(0);
        }   

        p[i&1].app(c);

        int was = (x - 1) / 3;
        if ((was & 1) != (c & 1)) {
            cout << "No" << endl;
            exit(0);
        }   

        inv[i&1] ^= t[0] != x;        
        x += 3;
    }

    int p_inv = get(p[0]) + get(p[1]);

    vector <int> ar(n), did(n);
    for (int i = 0; i < n; ++i) {
        ar.app(a[0][i] > a[2][i]);
    }       
    for (int i = 0; i + 2 < n; ++i) {
        did[i] = ar[i];
        for (int j = 1; j <= 2 && j <= i; ++j) {
            did[i] ^= did[i - j];
        }   
    }   
    for (int i = n - 2; i < n; ++i) {
        int have = 0;
        for (int j = 1; j <= 2 && j <= i; ++j) {
            have ^= did[i - j];
        }   
        if (have != ar[i]) {
            cout << "No" << endl;
            exit(0);
        }   
    }   

    if (get(p[0]) == inv[1] && get(p[1]) == inv[0]) {
        cout << "Yes" << endl;
    }   
    else {
        cout << "No" << endl;
    }   
}
