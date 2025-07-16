#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int h,w,ans = 0;
    int dx[4] = {-1,0,1,0},dy[4] = {0,-1,0,1};
    bool flag = true;

    cin >> h >> w;
    string s[h];

    rep(i,h) cin >> s[i];

    rep(i,h){
        rep(j,w){
            if(s[i][j] == '#'){
                flag = false;
                for(int a = 0;a < 4;a++){
                    if(i+dx[a] >= 0 && i+dx[a] < h  && j+dy[a] >= 0 && j+dy[a] < w && s[i+dx[a]][j+dy[a]] == '#')
                        flag = true;
                }
                if(flag == false){
                    cout << "No" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "Yes" << endl;

    return 0;
}