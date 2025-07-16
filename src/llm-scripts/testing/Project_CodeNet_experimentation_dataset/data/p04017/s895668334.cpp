#include<bits/stdc++.h>
using namespace std;
int n, l, q;
vector<int>v;
vector<vector<int> >moves;
void preprocess(){
    int cur = 1;
    for(int i = 1; i <= n; i++){
        while(cur <= n && v[cur] - v[i] <= l){
            cur++;
        }
        moves[i][0] = cur - 1;
    }
    for(int j = 1; j <= 17; j++){
        for(int i = 1; i <= n; i++){
            int mid = moves[i][j - 1];
            if(mid != -1){
                moves[i][j] = moves[mid][j - 1];
            }
        }
    }
}
int query(int l, int r){
    int ans = 0;
    if(l > r){
        swap(l, r);
    }
    for(int i = 17; i >= 0; i--){
        if(moves[l][i] == -1){
            continue;
        }
        if(moves[l][i] < r){
            l = moves[l][i];
            ans += 1 << i;
        }
    }
    ans++;
    return ans;
}
int main(){
    cin >> n;
    v.assign(n + 2, 0);
    moves.assign(n + 2, vector<int>(19, -1));
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    cin >> l >> q;
    preprocess();
    for(int i = 1; i <= q; i++){
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << '\n';
    }
    return 0;
}