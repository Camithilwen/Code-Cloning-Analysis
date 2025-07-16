#include<bits/stdc++.h>
#define reg register
using namespace std;
inline int  read() {
    reg int s = 0, t = 0; reg char ch = getchar();
    while(ch > '9' || ch < '0') t |= ch == '-', ch = getchar();
    while(ch >= '0' && ch <= '9') s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    return t ? -s : s;
}
int n, m, a[301][301], d[301], pos[301], sum[301], minn = 190090, ans;
int main()
{
    n = read(); m =  read();
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++) a[i][j] = read();
        sum[a[i][1]]++;
    }
    for(int i = m; i >= 1; i--){
        ans = 0;
        for(int j = 1; j <= m; j++) ans = max(ans, sum[j]);
        minn = min(minn, ans);
        for(int j = 1; j <= m; j++) {
            if(sum[j] == ans){   pos[j] = 1; break;}
        }
        for(int j = 1; j <= m; j++) sum[j] = 0;
        for(int j = 1; j <= n; j++) 
            for(int k = 1; k <= m; k++){
                if(!pos[a[j][k]]) {sum[a[j][k]]++; break;} 
            }
    }
    cout << minn;
}