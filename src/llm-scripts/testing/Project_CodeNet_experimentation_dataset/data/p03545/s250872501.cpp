#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define n1		      "\n"
#define B                     begin()
#define E                     end()
#define F                     first
#define S                     second
#define pb                    push_back
#define pf                    push_front
#define popb                  pop_back()
#define popf                  pop_front()

const int BIG=1e5+55;
const int BIGG=1e9+7;
const ll BIGGE=1e12+55;
const double SML=(1e-7);

using namespace std;

    int a[5];
    bool go = 0;

void dp(int i, int sum, string s) {
    if (go || i > 3)
        return;
    if (sum == 7 && i == 3) {
        go = 1;
        cout <<s <<'=' <<7;
        return;
    }
    string ans = s , an = s;
    ans += '-';
    ans += (a[i+1] + '0');
    if (i != -1)
        an  += '+';
    an  += (a[i+1] + '0');
    if (i != -1)
        dp(i+1 , sum-a[i+1] ,ans);
    dp(i+1 , sum+a[i+1] ,an);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    cout.tie(NULL);
    for (int i=0; i<4; i++) {
        char c;
        cin >>c;
        a[i] = c - '0';
    }
    dp(-1,0,"");



    return 0;
}
