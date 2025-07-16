#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
const int Q = 1e9 + 7;


inline void add(int &A , int B) {
    A += B;
    if (A >= Q) A -= Q;
}


map< pair<vector<bool>,bool> , int> h[2];

char str[N];

int main() {
    cin >> str;
    int cur = 0 , nxt = 1;
    h[cur][make_pair(vector<bool>(), false)] = 1;

    for (int i = 0 ; str[i] ; ++ i) {
        h[nxt].clear();
        int L = str[i] - '0' , R = str[i] - '0';
        if (str[i] == '?') L = 0 , R = 1;
        // cout << L << ' ' << R << endl;
        for (auto it : h[cur]) {
            //int s = it.first.first.size() + 1;
            for (int j = L ; j <= R ; ++ j) {
                vector<bool> p = it.first.first;
                p.emplace_back(j);
                int s = p.size();
                if (s >= 3 && !(p[s - 3] == 1 && p[s - 2] == 0 && j == 0)) {
                    int q = j + p[s - 3] + p[s - 2];
                    p.pop_back();
                    p.pop_back();
                    p.pop_back();
                    p.push_back(q >= 2);
                    s -= 2;
                }
                add(h[nxt][make_pair(p , it.first.second || (s > 1 && p[0] == 1 && p[1] == 1))] , it.second);
            }
        }
        swap(cur , nxt);
    }
    int res = 0;
    for (auto &it : h[cur]) {

        /*vector<bool> p = it.first.first;
        for (int i = 0 ; i < p.size() ; ++ i) {
            cout << p[i] << ' ';
            } cout << "|  " << it.first.second << ' ' << it.second << endl;*/


        if (it.first.second || it.first.first.size() == 1 && it.first.first[0]) {
            add(res , it.second);
        }
    }
    cout << res << endl;
}
