#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

const int MAX = 1000000;

int main() {
    string str;
    getline(cin, str);
    int j=0, o=0, i=0;
    int ans = 0;
    REP(t, str.length()) {
        if (str[t]=='J') {
            if (t>0 && str[t-1]=='O') j=0;
            j++;
            o=0;
            i=0;
        } else if (str[t]=='O') {
            o++;
            i=0;
            if (o>j) {
                j=0;
                o=0;
            }
        } else {
            i++;
            j=0;
            if (i>o) {
                o=0;
                i=0;
            }
            if (i==o) ans = max(ans, i);
        }
    }
    printf("%d\n", ans);
    return 0;
}