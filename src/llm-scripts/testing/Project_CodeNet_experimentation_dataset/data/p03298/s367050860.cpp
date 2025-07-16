#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;
using Map = unordered_map<string, long>;

size_t n;

void dfs(string src, Map &m, size_t i=0, string s="", string t="") {
    if (i == n){
        m[s + ' ' + t]++;
    } else {
        dfs(src, m, i+1, s+src[i], t);
        dfs(src, m, i+1, s, t+src[i]);
    }
}

int main() {
    string src;
    Map m1, m2;
    cin >> n >> src;
    string left  = src.substr(0, n),
           right = src.substr(n);
    reverse(right.begin(), right.end());
    dfs(left, m1);
    dfs(right, m2);
    long cnt = 0;
    for (auto mp:m1) 
        cnt += mp.second * m2[mp.first];
    cout << cnt << '\n';
    return 0;
}