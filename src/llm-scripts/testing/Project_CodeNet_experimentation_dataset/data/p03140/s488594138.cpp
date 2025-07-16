#include <bits/stdc++.h>
using namespace std;
#define repex(i, a, b, c) for(int i = a; i < b; i += c)
#define repx(i, a, b) repex(i, a, b, 1)
#define rep(i, n) repx(i, 0, n)
#define repr(i, a, b) for(int i = a; i >= b; i--)

int main(){
    
    // 1. 入力情報.
    int N;
    char A[111], B[111], C[111];
    scanf("%d %s %s %s", &N, A, B, C);
    
    // 2. 操作回数を保存.
    int ans = 0;
    rep(i, N){
        set<char> s;
        s.insert(A[i]);
        s.insert(B[i]);
        s.insert(C[i]);
        ans += s.size() - 1;
    }
    
    // 3. 出力.
    printf("%d\n", ans);
    return 0;
    
}