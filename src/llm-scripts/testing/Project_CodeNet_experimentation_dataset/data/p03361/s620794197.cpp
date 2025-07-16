#include<bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<int>> campas(h, vector<int>(w));
    for (int i=0; i<h; i++){
        string s;
        cin >> s;
        for (int j=0; j<w; j++){
            if (s[j] == '#') campas[i][j] = 1;
            else campas[i][j] = 0;
        }
    }
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            if (campas[i][j] == 0) continue;
            if ((0 <= i+1) && (i+1 < h)) {if (campas[i+1][j] > 0) campas[i][j] += 1;}
            if ((0 <= i-1) && (i-1 < h)) {if (campas[i-1][j] > 0) campas[i][j] += 1;}
            if ((0 <= j+1) && (j+1 < w)) {if (campas[i][j+1] > 0) campas[i][j] += 1;}
            if ((0 <= j-1) && (j-1 < w)) {if (campas[i][j-1] > 0) campas[i][j] += 1;}
        }
    }
    string ans="Yes";
    for (int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            if (campas[i][j] == 1) ans = "No";
        }
    }
    cout << ans << endl;
    return 0;
}