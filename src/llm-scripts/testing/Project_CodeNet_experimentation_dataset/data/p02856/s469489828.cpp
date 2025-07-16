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
    ll M; cin >> M;
    ll c[M], d[M];
    rep(i,M) cin >> d[i] >> c[i];
    ll res = 0;
    vector<int> N;
    rep(i,M){
        vector<ll> out;
        while(c[i] != 1){
            if(c[i]%2 == 1){
                out.push_back(d[i]);
                --c[i];
            }
            int d_tmp = d[i]+d[i];
            res += c[i]/2;
            if(d_tmp >= 10){
                d_tmp = 1 + (d_tmp%10);
                res += c[i]/2;
            }
            d[i] = d_tmp;
            c[i] /= 2;
        }
        for(int o: out){
            res++;
            int d_tmp = d[i]+o;
            if(d_tmp >= 10){
                res++;
                d_tmp = 1 + d_tmp % 10;
            }
            d[i] = d_tmp;
        }
        N.push_back(d[i]);
    }
    int m_tmp = -1;
    for(int m : N){
        if(m_tmp < 0){
            m_tmp = m;
        }else{
            res++;
            m_tmp = m_tmp + m;
            if(m_tmp >= 10){
                res++;
                m_tmp = 1 + (m_tmp % 10);
            }
        }
    }
    cout << res << endl;
}