#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (1e9)
#define INFL (1e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    int n; cin >> n;
    arr<int> A(n, vector<int>(n));
    vector<int> opp(n);
    rep(i, n){
        rep(j, n-1) {cin >> A[i][j]; A[i][j]--;}
        A[i][n-1] = -1;
        opp[i] = A[i][0];
    }

    vector<int> IND(n, 0);
    int ans = 0;
    int finished = 0;
    while(finished<n){
        ans++;
        // printf("day %d: ", ans);
        // rep(i, n) cout << opp[i] << " ";
        // pr("");

        vector<bool> seen(n, false);
        int game = 0;
        rep(i, n){
            
            if(IND[i]==n) continue;
            if(seen[i]) continue;
            seen[i] = true;
            if(IND[opp[i]]==n) continue;

            if(i == opp[opp[i]]){
                if(seen[opp[i]]) continue;
                int t = opp[i];
                // printf("%d: %d %d\n", ans+1, i, opp[i]);
                IND[i]++;
                IND[t]++;

                if(IND[i]==n-1) finished++;
                else opp[i] = A[i][IND[i]];

                if(IND[t]==n-1) finished++;
                else opp[t] = A[t][IND[t]];

                seen[t] = true;
                game++;
            }
        }
        if(game==0) {pr(-1); return 0;}
    }

    pr(ans);
    return 0;}