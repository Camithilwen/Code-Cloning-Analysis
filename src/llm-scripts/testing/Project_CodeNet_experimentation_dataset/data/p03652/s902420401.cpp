#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;

int main(){
    int N,M; cin >> N >> M;
    vector<vector<int>> A(N,vector<int>(M));
    rep(i,N)rep(j,M){
        cin >> A[i][j];
        A[i][j]--;
    }
    vector<int> id(N);
    vector<vector<bool>> used(N,vector<bool>(M,false));
    int ans = INF;
    while(true){
        vector<int> s(M);
        bool ok = true;
        rep(i,N){
            while(used[i][id[i]]){
                id[i]++;
                if(id[i] >= M) ok = false;
            }
            if(!ok) break;
            s[A[i][id[i]]]++;

        }
        if(!ok) break;
        int now = 0;
        int dame = 0;
        rep(i,M){
            if(now < s[i]){
                now = s[i];
                dame = i;
            }
        }
        rep(i,N)rep(j,M){
            if(A[i][j] == dame) used[i][j] = true;
        }
        ans = min(ans,now);
    }
    cout << ans << endl;
}
