#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vbb;
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;

#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define mp make_pair

#define loop(i,a,b) for(int i=(a);i<ull(b);++i)
#define rep(i,n) loop(i,0,n)

const double eps = 1e-10;
const double pi  = acos(-1.0);
const double inf = (int)1e8;

int main(){
    int d[110];
    int n, q;
    while(cin >> n >> q, n+q){
        fill(d, d+110, 0);
        for(int i=0; i< n; i++){
            int q;
            cin >> q;
            rep(j, q){
                int r; cin >> r; d[r]++;
            }
        }
        int m = 0, ret = -1;
        rep(i, 110){
            if(q <= d[i] && m < d[i]){ret = i; m = d[i];}
        }
        cout << (ret==-1?0:ret) << endl;
    }
}