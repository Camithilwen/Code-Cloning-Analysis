#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    string s;
    cin >> s;
    string t;
    cin >> t;
    int max_length = 0;
    for (int i = 1; i <= N; i++){
        if (s.substr(N - i, i) == t.substr(0, i)) max_length = i;
    }
    cout << 2 * N - max_length << endl;
}
