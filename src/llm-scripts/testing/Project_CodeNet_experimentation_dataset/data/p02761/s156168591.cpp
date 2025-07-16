#include<iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using P = pair<int,int>;

/* 大文字を小文字に変換 */
char tolower(char c) {return (c + 0x20);}
/* 小文字を大文字に変換 */
char toupr(char c) {return (c - 0x20);}

// if('A'<=s[i] && s[i]<='Z') s[i] += 'a'-'A';

/*
string s = "abcdefg"
s.substr(4) "efg"
s.substr(0,3) "abc"
s.substr(2,4) "cdef"

// イテレータ要素のインデックス
distance(A.begin(), itr);
*/

const int INF = 1000100100;

int main()
{
    int n; cin >> n;
    int m; cin >> m;
    int s[m], c[m];
    rep(i,m) cin >> s[i] >> c[i];

    int rn, sn;
    if(n == 1) rn = 10, sn = 0;
    else if(n == 2) rn = 100, sn=10;
    else rn = 1000,sn=100;

    int res = INF;
    for(int i=sn; i<rn; i++){
        int cnt = 0;
        rep(j,m){
            int sj = n-s[j]+1;
            int num;
            if(sj == 1){
                num = i%10;
                if(c[j] == num) cnt++;
            }else if(sj ==2){
                num = i / 10;
                num %= 10;
                if(c[j] == num) cnt++;
            }else{
                num = i/100;
                if(c[j] == num) cnt++;
            }
        }
        if(cnt == m) res = min(i, res);
    }

    if(res == INF) cout << -1 << endl;
    else cout << res << endl;
}