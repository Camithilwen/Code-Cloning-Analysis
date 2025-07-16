# include <iostream>
# include <string>
# include <algorithm>
# include <vector>
# include <cstring>
# include <stdio.h>
# include <map>
# include <queue>

# define ll long long
# define pii pair<int,int>
# define FOR(a,b) for(int a=1; a<=b; a++)
# define REP(a,b) for(int a=0; a<b; a++)
# define FORU(a,b,c) for(int a=b; a<=c; a++)
# define FORD(a,b,c) for(int a=b; a>=c; a--)

using namespace std;

char grid[2005][2005];
int tok[2005][2005];
int h[2005], w[2005];

int R, C;

int main(){

    ios :: sync_with_stdio(false);
    cin >> R >> C;
    FOR(i,R) FOR(j,C){
        cin >> grid[i][j];
    }

    int ans = max(R,C);
    FOR(i,R-1){
        FOR(j,C-1){
            int black = (grid[i][j] == '#') + (grid[i][j+1] == '#') + (grid[i+1][j] == '#') + (grid[i+1][j+1] == '#');
            tok[i][j] = black&1;
        }
    }

    FOR(i,R){
        FOR(j,C-1){
            if(tok[i-1][j]) h[j] = 1;
            else h[j]++;
        }

        int k = 0;
        FOR(j,C-1){
            while(h[j] <= h[w[k]]){
                ans = max(ans, h[w[k]]*(j - w[k-1]));
                k--;
            }
            w[++k] = j;
        }

        while(k > 0){
            ans = max(ans, h[w[k]] * (C - w[k-1]));
            k--;
        }
    }

    cout << ans << endl;
    return 0;
}