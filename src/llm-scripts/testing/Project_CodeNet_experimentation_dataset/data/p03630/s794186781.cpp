#include<bits/stdc++.h>
using namespace std;
#define _   int v, int tl, int tr, int l, int r
#define tm  (tl + tr >> 1)
#define sol v+v, tl, tm, l, r
#define sag v+v+1, tm+1, tr, l, r
#define pb push_back
#define mp make_pair
#define st first
#define nd second
typedef pair < int , int > pp;
const int mod = 1e9 + 7;
const int N   = 2e3 + 3;    

char s[N][N];
int sam[N],dif[N];

signed main(){  
    int m,n;
    cin >> m >> n;
    for(int i=1; i<=m; i++)
        scanf(" %s", s[i]+1);
    
    int ans = max(m,n);
    for(int j=1; j<=n; j++){
        stack < pp > S;
        S.push(mp(-1,1));
        for(int i=2; i<=m+1; i++){
            int x = 0;
            if(s[i][j] == s[i-1][j]){
        		x = ++sam[i];
                dif[i] = 0;
            }   
            else{
                x = ++dif[i];
               	sam[i] = 0; 
            }
            if(i == m+1) x = 0;
            
            for(; S.top().st >= x;){
                int t = S.top().st;
                S.pop();
                ans = max(ans , t * (i-S.top().nd));
            }
            S.push(mp(x,i));
        }
    }
    
    cout << ans;
    return 0;
}