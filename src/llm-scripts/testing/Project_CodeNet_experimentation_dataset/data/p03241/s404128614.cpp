#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
//const int INF = 2e9;
//const ll INF = 9e18;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    if (N==1){
        cout << M << "\n";
        return 0;
    }
    vector<int> div;
    for (int i=1;i*i<=M;i++){
        if (M%i == 0){
            div.push_back(i);
            if (i*i!=M){
                div.push_back(M/i);
            }
        }
    }
    sort(div.begin(),div.end());
    int p = 0;
    for (int i=0;i<div.size();i++){
        if ((ll)div[i]*(ll)N>(ll)M) {
            p = i;
            break;
        }
    }
    int ans;
    ans = div[p-1];
    cout << ans << "\n";
}