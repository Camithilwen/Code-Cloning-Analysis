#include <bits/stdc++.h>
using namespace std;
int x[200005], y[200005], d[200005];
vector<int> U[200005], D[200005], R[200005], L[200005];
vector<int> UL1[400005], UL2[400005];
vector<int> UR1[400005], UR2[400005];
vector<int> DL1[400005], DL2[400005];
vector<int> DR1[400005], DR2[400005];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        char s[2];
        scanf("%d%d%s", &x[i], &y[i], s);
        if(s[0] == 'U'){
            d[i] = 0;
            U[x[i]].emplace_back(y[i]);
            UL1[x[i]-y[i]+200000].emplace_back(y[i]);
            UR1[x[i]+y[i]].emplace_back(y[i]);
        }
        else if(s[0] == 'D'){
            d[i] = 1;
            D[x[i]].emplace_back(y[i]);
            DL1[x[i]+y[i]].emplace_back(y[i]);
            DR1[x[i]-y[i]+200000].emplace_back(y[i]);
        }
        else if(s[0] == 'R'){
            d[i] = 2;
            R[y[i]].emplace_back(x[i]);
            UR2[x[i]+y[i]].emplace_back(y[i]);
            DR2[x[i]-y[i]+200000].emplace_back(y[i]);
        }
        else{
            d[i] = 3;
            L[y[i]].emplace_back(x[i]);
            UL2[x[i]-y[i]+200000].emplace_back(y[i]);
            DL2[x[i]+y[i]].emplace_back(y[i]);
        }
    }
    for(int i=0;i<=200000;i++){
        sort(U[i].begin(), U[i].end());
        sort(D[i].begin(), D[i].end());
        sort(R[i].begin(), R[i].end());
        sort(L[i].begin(), L[i].end());
    }
    for(int i=0;i<=400000;i++){
        sort(UL1[i].begin(), UL1[i].end());
        sort(UL2[i].begin(), UL2[i].end());
        sort(UR1[i].begin(), UR1[i].end());
        sort(UR2[i].begin(), UR2[i].end());
        sort(DL1[i].begin(), DL1[i].end());
        sort(DL2[i].begin(), DL2[i].end());
        sort(DR1[i].begin(), DR1[i].end());
        sort(DR2[i].begin(), DR2[i].end());
    }
    int ans = 1e9;
    for(int i=0;i<=200000;i++){
        for(int j=0;j<U[i].size();j++){
            int y = U[i][j];
            int k = lower_bound(D[i].begin(), D[i].end(), y) - D[i].begin();
            if(k == D[i].size()) continue;
            ans = min(ans, (D[i][k]-y)*5);
        }

        for(int j=0;j<R[i].size();j++){
            int x = R[i][j];
            int k = lower_bound(L[i].begin(), L[i].end(), x) - L[i].begin();
            if(k == L[i].size()) continue;
            ans = min(ans, (L[i][k]-x)*5);
        }
    }
    for(int i=0;i<=400000;i++){
        for(int j=0;j<UL1[i].size();j++){
            int y = UL1[i][j];
            int k = lower_bound(UL2[i].begin(), UL2[i].end(), y) - UL2[i].begin();
            if(k == UL2[i].size()) continue;
            ans = min(ans, (UL2[i][k]-y)*10);
        }

        for(int j=0;j<UR1[i].size();j++){
            int y = UR1[i][j];
            int k = lower_bound(UR2[i].begin(), UR2[i].end(), y) - UR2[i].begin();
            if(k == UR2[i].size()) continue;
            ans = min(ans, (UR2[i][k]-y)*10);
        }

        for(int j=0;j<DL1[i].size();j++){
            int y = DL1[i][j];
            int k = lower_bound(DL2[i].begin(), DL2[i].end(), y) - DL2[i].begin() - 1;
            if(k < 0) continue;
            ans = min(ans, (y-DL2[i][k])*10);
        }

        for(int j=0;j<DR1[i].size();j++){
            int y = DR1[i][j];
            int k = lower_bound(DR2[i].begin(), DR2[i].end(), y) - DR2[i].begin() - 1;
            if(k < 0) continue;
            ans = min(ans, (y-DR2[i][k])*10);
        }
    }


    if(ans == 1e9) printf("SAFE\n");
    else printf("%lld\n", ans);
}