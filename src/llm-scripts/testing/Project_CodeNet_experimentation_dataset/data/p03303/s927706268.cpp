#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    string S;
    int w;
    cin >> S >> w;
    for (int i = 0; i < S.size(); i += w){
        cout << S.at(i);
    }
    cout << endl;
}

