#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int>v(m + 3), v2, stick(12), val(12, -1), vis(12, 0);
    stick[1] = 2, stick[2] = 5, stick[3] = 5, stick[4] = 4, stick[5] = 5, stick[6] = 6, stick[7] = 3, stick[8] = 7, stick[9] = 6;
    for(int i = 0; i < m; i++){
        cin >> v[i];
        if(vis[stick[v[i]]] == 0){
            vis[stick[v[i]]] = 1;
            v2.push_back(stick[v[i]]);
        }
        val[stick[v[i]]] = max(val[stick[v[i]]], v[i]);
    }
    int dp[n + 3];
    for(int i = 0; i <= n; i++){
        dp[i] = -1;
    }
    dp[0] = 0;
    for(int i = 0; i < v2.size(); i++){
        for(int j = v2[i]; j <= n; j++){
            if(dp[j - v2[i]] != -1){
                dp[j] = max(dp[j], dp[j - v2[i]] + 1);
            }
        }
    }
    vector<pair<int, int> >vec;
    for(int i = 0; i < v2.size(); i++){
        vec.push_back(make_pair(val[v2[i]], v2[i]));
    }
    sort(vec.rbegin(), vec.rend());
    string s;
    int cnt = 0;
    while(n > 0){
        cnt++;
        for(int j = 0; j < vec.size(); j++){
            if(n - vec[j].second >= 0 && dp[n] == dp[n - vec[j].second] + 1){
                s.push_back('0' + vec[j].first);
                n = n - vec[j].second;
                break;
            }
        }
    }
    cout << s;
    return 0;
}