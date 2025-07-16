#include<stdio.h>
#include<algorithm>
#include<vector>
#define fst first
#define snd second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

char three[3][4] = {
    "xx.",
    "..y",
    "..y"
};

char four[4][5] = {
    "aacd",
    "bbcd",
    "cdaa",
    "cdbb"
};

char five[5][6] = {
    "aabbc",
    "dx..c",
    "dx..b",
    "a.yyb",
    "accdd"
};

char six[6][7] = {
    "aacd..",
    "bbcd..",
    "..aacd",
    "..bbcd",
    "cd..aa",
    "cd..bb"
};

char seven[7][8] = {
    "aabbcc.",
    "xx.xx.a",
    "..y..ya",
    "..y..yb",
    "xx.xx.b",
    "..y..yc",
    "..y..yc"
};

char ans[1000][1000 + 1];

int main() {
    int n;
    scanf("%d", &n);
    if (n == 2) return !puts("-1");
    if (n == 3) {
        for(int i = 0; i < 3; i++)
            puts(three[i]);
    }
    else {
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ans[i][j] = '.';

        for(int st = 0; st < n;) {
            if (n - st == 5) {
                for (int i = 0; i < 5; i++) for (int j =0; j < 5; j++) {
                    ans[st + i][st + j] = five[i][j];
                }
                st += 5;
            }
            else if (n - st == 6) {
                for (int i = 0; i < 6; i++) for (int j = 0; j < 6; j++) {
                    ans[st + i][st + j] = six[i][j];
                }
                st += 6;
            }
            else if (n - st == 7) {
                for (int i = 0; i < 7; i++) for (int j = 0; j < 7; j++) {
                    ans[st + i][st + j] = seven[i][j];
                }
                st += 7;
            }
            else {
                for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
                    ans[st + i][st + j] = four[i][j];
                }
                st += 4;
            }
        }
        
        for (int i = 0; i < n; i++)
            puts(ans[i]);
    }
    return 0;
}