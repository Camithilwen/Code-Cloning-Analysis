// ※※※ 解答不能 ※※※
// Um_nik氏
// https://atcoder.jp/contests/agc041/submissions/9181788
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)
const int N = 1010;
int n;
char s[N][N];
char a[4][5] = {
    "aabc",
    "ddbc",
    "efgg",
    "efhh"
};
char b[5][6] = {
    "aabbc",
    "dee.c",
    "d..fg",
    "h..fg",
    "hiijj"
};
char c[7][8] = {
    "aabbc..",
    "d...cee",
    "dffgg..",
    "hh...ij",
    "..k..ij",
    "..k..lm",
    "...nnlm"
};

void solve(vector<int> w){
    int p = 0;
    for(int x : w){
        if(x == 4)      rep(i, x) rep(j, x) s[p + i][p + j] = a[i][j];
        else if(x == 5) rep(i, x) rep(j, x) s[p + i][p + j] = b[i][j];
        else if(x == 7) rep(i, x) rep(j, x) s[p + i][p + j] = c[i][j];
        p += x;
    }
}

int main(){
    scanf("%d", &n);
    if(n == 2){
        printf("-1\n");
        return 0;
    }
    rep(i, n) rep(j, n) s[i][j] = '.';
    if(n % 3 == 0){
        repex(i, 0, n, 3) s[i][i] = s[i][i + 1] = s[i + 1][i + 2] = s[i + 2][i + 2] = 'a';
    }else{
        if(n == 7){
            solve({7});
        }else if (n == 11){
            solve({4, 7});
        }else{
            vector<int> w;
            int x = n;
            while(x % 4 != 0){
                w.push_back(5);
                x -= 5;
            }
            if(x < 0) throw;
            while(x > 0){
                w.push_back(4);
                x -= 4;
            }
            solve(w);
        }
    }
    rep(i, n){
        s[i][n] = '\0';
        printf("%s\n", s[i]);
    }
    return 0;
}