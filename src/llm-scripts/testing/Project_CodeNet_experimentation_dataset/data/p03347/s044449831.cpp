#include <bits/stdc++.h>
using namespace std;
int a[200002], b[200002];
int main(){
    int n;
    scanf("%d", &n);
    bool ok = 1;
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        if(a[i] > a[i-1] && a[i]-a[i-1] > 1){
            ok = 0;
        }
        if(i == 1 && a[i] != 0){
            ok = 0;
        }
    }   
    if(!ok) printf("-1\n");
    else{
        long long ans = 0;
        for(int i=n;i>=1;i--){
            if(a[i] == 0) continue;
            if(a[i]+1 == a[i+1]) continue;
            ans += a[i];
        }
        printf("%lld\n", ans);
    }
}