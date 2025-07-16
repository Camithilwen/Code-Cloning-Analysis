#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

int main() {
    int A, B; cin >> A >> B; A--, B--;
    vector<string> g(50,string(100,'#'));
    vector<string> g2(50,string(100,'.'));
    g.insert(g.end(),g2.begin(),g2.end());
    int i = 0; int j = 0;
    while(A--){
        g[i][j] = '.';
        j += 2;
        if(j >= 100){
            j -= 100;
            i += 2;
        }
    }
    i = 51; j = 0;
    while(B--){
        g[i][j] = '#';
        j += 2;
        if(j >= 100){
            j -= 100;
            i += 2;
        } 
    }
    cout << "100 100\n"; 
    REP(i,100) cout << g[i] << endl;
}