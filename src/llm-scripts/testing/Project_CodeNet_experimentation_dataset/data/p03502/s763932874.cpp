#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using P = pair<int, int>;
int main()
{   
    int n;
    cin >> n;
    string m = to_string(n);
    int cnt = 0;
    rep(i,m.size()){
        cnt += m.at(i) - '0';
    }
    if(n % cnt == 0)cout << "Yes" << endl;
    else cout << "No" << endl;
return 0;
}