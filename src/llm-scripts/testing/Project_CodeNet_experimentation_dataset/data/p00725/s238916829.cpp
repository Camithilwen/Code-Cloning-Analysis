#include<bits/stdc++.h>
using namespace std;

int di[4] = {0, -1, 0, 1};
int dj[4] = {1, 0, -1, 0};

void game(int n, int& ans, int ni, int nj, int gi, int gj, vector<vector<int> >& table){

    if(ni == gi && nj == gj){
        if(ans == -1) ans = n;
        else ans = min(ans, n);
        return;
    }else if(n == 10){
        return;
    }else{

        for(int h = 0; h < 4; h++){
            int nexti = ni;
            int nextj = nj;
            if(table[ni + di[h]][nj + dj[h]] == 1) continue;
            while(1){
                nexti += di[h];
                nextj += dj[h];
                if(table[nexti][nextj] == 1){
                    table[nexti][nextj] = 0;
                    game(n + 1, ans, nexti - di[h], nextj - dj[h], gi, gj, table);
                    table[nexti][nextj] = 1;
                    break;
                }else if(table[nexti][nextj] == 3){
                    game(n + 1, ans, nexti, nextj, gi, gj, table);
                    break;
                }else if(table[nexti][nextj] == -1){
                    break;
                }
            }
        }
    }
    return;
}

int main(){

    while(1){
        int w, h; cin >> w >> h;
        if(!w) break;

        int si, sj, gi, gj;
        vector<vector<int> > table(h + 2, vector<int> (w + 2, -1));
        for(int i = 1; i <= h; i++){
            for(int j = 1; j <= w; j++){
                cin >> table[i][j];
                if(table[i][j] == 2){
                    si = i;
                    sj = j;
                    table[i][j] = 0;
                }
                if(table[i][j] == 3){
                    gi = i;
                    gj = j;
                }
            }
        }

        int ans = -1;
        game(0, ans, si, sj, gi, gj, table);

        cout << ans << endl;
    }

    return 0;
}
