#include <bits/stdc++.h>
#define REP(i, e) for(int (i) = 0; (i) < (e); ++(i))
#define FOR(i, b, e) for(int (i) = (b); (i) < (e); ++(i))
#define ALL(c) (c).begin(), (c).end()
#define PRINT(x) cout << (x) << "\n"
using namespace std;
using ll = long long; using pint = pair<int, int>; using pll = pair<ll, ll>;
template<typename T> auto compare = [](T x, T y) -> bool{return (x < y);};
const int MOD = 1000000007;

int N, a[100010];
string S;


signed main(){
    cin >> N >> S;
    REP(st, 4){
        if(st & 1){
            a[0] = 1;
            if(st & 2) a[N - 1] = 1;
            else a[N - 1] = 0;
        }else{
            a[0] = 0;
            if(st & 2) a[N - 1] = 1;
            else a[N - 1] = 0;
        }
        REP(i, N){
            if(a[i] == 0){
                if(S[i] == 'o') a[(i + 1 + N) % N] = a[(i - 1 + N) % N]; 
                else a[(i + 1 + N) % N] = 1 - a[(i - 1 + N) % N];
            }else{
                if(S[i] == 'o') a[(i + 1 + N) % N] = 1 - a[(i - 1 + N) % N]; 
                else a[(i + 1 + N) % N] = a[(i - 1 + N) % N];
            }
        }
        if(st & 1){
            if(a[0] == 0) continue;
            if(st & 2){
                if(a[N - 1] == 0) continue;
            }else{
                if(a[N - 1] == 1) continue;
            }
        }else{
            if(a[0] == 1) continue; 
            if(st & 2){
                if(a[N - 1] == 0) continue;
            }else{
                if(a[N - 1] == 1) continue;
            }
        }
        REP(i, N){
            if(a[i] == 0) cout << "S";
            else cout << "W";
        }
        cout << endl;
        return 0;
    }
    PRINT("-1");
    return 0;
}