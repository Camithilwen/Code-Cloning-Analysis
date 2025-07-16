#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

string s;

int main(void){
    cin >> s;
    stack<char> st;
    lli ans = s.size();
    rep(i, s.size()){
        if(s[i] == 'S'){
            st.push('S');
        }else if(s[i] == 'T'){
            if(!st.empty() && st.top() == 'S'){
                ans-=2;
                st.pop();
            }else st.push('T');
        }
    }
    cout << ans << endl;
    return 0;
}
