#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

int main(){
    int n, K;
    cin >> n >> K;
    int v[n];
    rep(i, n) cin >> v[i];
    int mx = min(n, K);
    int ans = 0;
    for (int i = 0; i <= mx; i++){
        for (int j = 0; j <= i; j++){
            vec v_s;
            for (int k = 0; k < j; k++){
                v_s.push_back(v[k]);
            }
            for (int k = n - 1; k > (n - 1) - (i - j); k--){
                v_s.push_back(v[k]);
            }
            sort(v_s.begin(), v_s.end());
            // for (int k = 0; k < v_s.size(); k++){
            //     cout << v_s[k] << " ";
            // }cout << endl;
            
            int sm = 0;
            rep(k, v_s.size()){
                if(k < K - i && v_s[k] < 0) continue;
                sm += v_s[k];
            }
            // cout << sm << endl;
            ans = max(sm, ans);
        }
    }
    cout << ans << endl;
}