#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define vv(T) vector<vector<T>>
#define coa cout << ans << endl; return 0;
using namespace std;
using ll = long long;
template<typename T>
using vec = vector<T>;
template<typename T>
using vvec = vector<vector<T>>;
using qint = queue<int>;
using sint = stack<int>;
using pii = pair<int, int>;


int main(){
    string s;
    cin >> s;

    map<int, int> alphabet;
    for(auto c : s){
        alphabet[c]++;
    }
    
    string ans;
    for(char c = 'a'; c <= 'z'; c++){
        if(alphabet[c] == 0){
            ans.push_back(c);
        }
    }

    if(ans.empty()) ans += "None";
    else ans = ans[0];

    coa
}
