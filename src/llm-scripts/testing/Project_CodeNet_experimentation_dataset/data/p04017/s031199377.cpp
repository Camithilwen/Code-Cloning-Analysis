#include <bits/stdc++.h>
using namespace std;
int x[100005];
int par1[17][100005], par2[17][100005];
int main(){
    int n, l, q;
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &x[i]);
    scanf("%d%d", &l, &q);
    for(int i=1;i<=n-1;i++){
        int lo = i+1, hi = n, ans;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(x[mid]-x[i] <= l) ans = mid, lo = mid+1;        
            else hi = mid-1;
        }
        par1[0][i] = ans;
    }
    for(int i=n;i>=2;i--){
        int lo = 1, hi = i-1, ans;
        while(lo <= hi){
            int mid = (lo+hi)/2;
            if(x[i]-x[mid] <= l) ans = mid, hi = mid-1;
            else lo = mid+1;
        }
        par2[0][i] = ans;
    }
    for(int j=1;j<17;j++){
        for(int i=1;i<=n;i++){
            if(par1[j-1][i] != 0) par1[j][i] = par1[j-1][par1[j-1][i]];
            if(par2[j-1][i] != 0) par2[j][i] = par2[j-1][par2[j-1][i]];
        }
    }
    for(int i=1;i<=q;i++){
        int a, b, ans = 0;
        scanf("%d%d", &a, &b);
        if(a < b){
            for(int j=16;j>=0;j--){
                if(par1[j][a] == 0) continue;
                if(par1[j][a] <= b){
                    a = par1[j][a];
                    ans += (1<<j);
                }
            }

            if(a != b) ans++;
        }
        else{
            for(int j=16;j>=0;j--){
                if(par2[j][a] == 0) continue;
                if(par2[j][a] >= b){
                    a = par2[j][a];
                    ans += (1<<j);
                }
            }
            if(a != b) ans++;
        }
        printf("%d\n", ans);
    }
}