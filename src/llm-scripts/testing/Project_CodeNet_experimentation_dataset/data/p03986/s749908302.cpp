#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)

int main(){
    
    // 1. 入力情報.
    char X[202020];
    scanf("%s", X);
    int l = strlen(X);
    
    // 2. 'T' が 来たら, stack から 'S' を 取り除く.
    stack<char> st;
    rep(i, l){
        char c = X[i];
        if(st.empty()){
            st.push(c);
            continue;
        }
        char t = st.top();
        if(c == 'T' && t == 'S') st.pop();
        else                     st.push(c);
    }
    
    // 3. 出力.
    printf("%d\n", st.size());
    return 0;
    
}