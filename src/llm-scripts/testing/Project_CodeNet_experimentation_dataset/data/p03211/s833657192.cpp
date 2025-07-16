#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;

int main(){
    // 制約見て！！！デカかったらlong longにすること！
    string s;
    cin >> s;
    int m = 753;
    rep(i,s.size()-2){
        string sub = s.substr(i,3);
        int x = stoi(sub);
        m = std::min(m,abs(x-753));
    }
    cout << m <<endl;
}