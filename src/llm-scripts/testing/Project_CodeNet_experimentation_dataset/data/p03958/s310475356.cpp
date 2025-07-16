#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, b) for (int i = 0; i < (b); i++ )

typedef pair<int,int> P;
typedef long long ll;

const int INF = 100000000;
const double PI=acos(-1);

ll dp[10010][2][110];

int main(){
    int K,T;
    cin >> K >> T;
    map<int,int> S;
    rep(i,T) {
        int tmp;
        cin >> tmp;
        S[i]=tmp;
    }
    vector<int> A(1,-1);

    rep(i,K) {
        int idx,idx_max;
        int num,num_max;
        idx = idx_max = -1;
        num = num_max = -1;

        rep(j,T) {
            if (S[j]>num && S[j]>0) {
                idx = j;
                num = S[j];
            }
            if (S[j]>num_max && S[j]>0 && A[i]!=j) {
                idx_max = j;
                num_max = S[j];
            }
        }
        if (idx_max!=-1) {
            A.push_back(idx_max);
            S[idx_max]--;
        }
        else {
            A.push_back(idx);
            S[idx]--;           
        }
    }
    int ans = 0;
    rep(i,A.size()-1) {
        if (A[i]==A[i+1]) {
            ans++;
        }
    }

    cout << ans << endl;
}
