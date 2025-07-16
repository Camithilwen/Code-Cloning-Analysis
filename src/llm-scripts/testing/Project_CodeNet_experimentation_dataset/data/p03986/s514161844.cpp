#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;


int main(){
    string s;cin >>s;
    stack<char> st;
    st.push(s[0]);
    rep(i,s.size()-1){
        
        char ch = '.';
        if(st.size()){
            ch = st.top();
            //cout << ch << endl;
        }
        if(s[i+1]=='T'&&ch=='S'){
            st.pop();
        }else{
            st.push(s[i+1]);
        }
    }

    cout << st.size() <<endl;
 }