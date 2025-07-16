#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 5;
string s;
void solve(){
    stack<char> st;
    int i = 0, n = s.length();
    for(i = 0; i < n; i++){
        if(s[i] == 'S')
            st.push(s[i]);
        else{
            if(st.size() > 0 && st.top() == 'S')
                st.pop();
            else
                st.push(s[i]);
        }
    }
    cout << st.size() << "\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    solve();
    return 0;
}