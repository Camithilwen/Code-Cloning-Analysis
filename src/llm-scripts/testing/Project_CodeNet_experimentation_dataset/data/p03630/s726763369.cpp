#include <bits/stdc++.h>
using namespace std;

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<int>> S(H);
    for(int i=0; i<H; i++){
        string s;
        cin >> s;
        for(int j=0; j<W; j++) S[i].push_back(s[j] == '#');
    }
    int ans = max(H, W);
    vector<int> h(W);
    for(int i=0; i<H; i++){
        stack<pair<int, int>> st;
        for(int j=0; j<W; j++){
            int pos = j;
            while(st.size() && st.top().first > h[j]){
                auto& p = st.top();
                int res = (p.first+1) * (j-p.second+1);
                ans = max(ans, res);
                pos = p.second;
                st.pop();
            }
            if(st.size() == 0 || st.top().first < h[j]) st.push({h[j], pos});
        }
        if(i<H-1) for(int j=0; j<W-1; j++){
            if((S[i][j] + S[i+1][j] + S[i][j+1] + S[i+1][j+1]) % 2){
                h[j] = 0;
            }else{
                h[j]++;
            }
        }
    }
    cout << ans << endl;
}