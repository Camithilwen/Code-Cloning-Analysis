// Made by Luis Miguel Baez
// es.luismiguelbaez@gmail.com

#include <bits/stdc++.h>
 
using namespace std;

#define endl '\n'
#define precise(n,k) fixed << setprecision(k) << n
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define uint  unsigned int
#define ll    long long
#define ull   unsigned long long
#define ld    long double

#define pii   pair<int, int>
#define piii  pair<int, pair<int, int>>
#define pll   pair<ll, ll>

#define F  first
#define S  second
#define PB push_back
#define MP make_pair

#define debug(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

string to_string(string s) {
    return '"' + s + '"';
}

string to_string(bool b) {
    return (b ? "true" : "false");
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename T>
string to_string(const vector<T> &v) {
    bool first = true;
    string res = "{";
    for (const T &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string((T)x);
    }
    res += "}";
    return res;
}

// add templates here

template<class T>
void println(const T &data) {
    cout << to_string((T)data) << endl;
}

template <typename T>
void write(vector<T> &v, bool size=true) {
    if(size) cout << v.size() << endl;
    string res = "";
    for(const T &x: v) {
        res += to_string((T)x) + " ";
    }
    cout << res << endl;
}

template <typename T>
void read(vector<T> &v) {

    for(const T &x: v) {
        cin >> x;   
    }
}

const int MOD = int(1e9+7);
const int oo  = int(1e9 + 20);
const ll lloo  = (ll)(1e18 + 10);


#define NEUTRAL_MIN -oo
// Limite de la longitud del Array
const int N = 100000 + 20;

int n; // Tamaño del Arreglo

// Maximo Tamaño del Arbol
int tree[2 * N];

// Funcion que Construye el Arbol
void build( vector<int> arr) {

    for (int i=0; i<n; i++){
        tree[n+i] = arr[i];
    }

    // construye el árbol calculando a los padres
    for (int i = n - 1; i > 0; --i) {
        tree[i] = max(tree[i<<1], tree[i<<1 | 1]);
    }
}

// Función para actualizar un nodo de árbol
void updateTreeNode(int index, int value) {
    // Establecer el valor en la posición p
    tree[index+n] = value;
    index = index + n;

    // Moverse hacia arriba y actualizar a los padres
    for (int i = index; i > 1; i >>= 1){
        tree[i>>1] = max(tree[i], tree[i^1]);
    }
}

// función para obtener la suma en el intervalo [l, r)

int query(int l, int r) {
    int ans = NEUTRAL_MIN;

    // bucle para encontrar la suma en el rango
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) {
            ans = max(ans, tree[l++]);
        }

        if (r&1) {
            ans = max(ans, tree[--r]);
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    n++;
    vector<int> val(n);
    for(int i = 1; i < n; ++i) {
        cin >> val[i];
    }
    build(val);
    
    vector<bool> visited(n, false);
    int colors = 0;
    int last;
    for(int i = 1; i < n; ++i) {
        if(!visited[i]) {
            colors++;
            last = val[i];
            visited[i] = true;
            updateTreeNode(i, -oo);
            
            if(query(i+1, n) <= last) continue;
            
            for(int j = i + 1; j < n; ++j) {
                if(!visited[j] && last < val[j]) {
                    last = val[j];
                    visited[j] = true;
                    updateTreeNode(j, -oo);
                    if(query(j+1, n) <= last) break;
                }
            }
        }
    }
    cout << colors << endl;

    return 0;
}