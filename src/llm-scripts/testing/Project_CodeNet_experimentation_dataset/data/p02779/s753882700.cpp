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

int main()
{
    map<int,int> m;
    int n; cin >> n;
    int a[n];
    rep(i,n) cin >> a[i];

    rep(i,n) m[a[i]]++;

    bool isok = true;
    rep(i,n){
        if(m[a[i]] > 1){
            isok = false;
            break;
        }
    }
    if(isok) cout << "YES" << endl;
    else cout << "NO" << endl;
}