#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 5;
char s[maxn];
int sum[maxn];
int k[maxn];
vector<int> D;
vector<int> C;
int n;
ll slove(int k) {
    if (C.empty() || D.empty())
        return 0;
    ll ans=0;
    int j = 0;
    queue<int> q;
    int a, b;
    ll temp=0;
    for (int i = 0; i < D.size(); i++) {
        //将所有C的贡献调整
        if(i>0)
            temp-=(ll)q.size()*(sum[D[i]]-sum[D[i-1]]);
        //将跳过的C贡献调整
        if(!q.empty()) {
            int ft=q.front();
            while(ft<=D[i]) {
                temp+=sum[D[i]]-sum[D[i-1]];
                temp-=sum[ft]-sum[D[i-1]];
                q.pop();
                if(q.empty())
                    break;
                ft=q.front();
            }
        }
        //将无用的C排除
        while(j < C.size() &&C[j]<D[i]){
            j++;
        }
        //增加新的C
        while (j < C.size() && C[j] - D[i] < k) {
            q.push(C[j]);
            temp+=sum[C[j]]-sum[D[i]];
            j++;
        }
        ans+=temp;
    }
    return ans;
}
int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    int q;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
        scanf("%d", &k[i]);
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'D')
            D.push_back(i);
        if (s[i] == 'C')
            C.push_back(i);
        if (s[i] == 'M')
            sum[i] = sum[i - 1] + 1;
        else
            sum[i] = sum[i - 1];
    }
//    cout<<"D";
//    for(auto x:D)cout<<x<<" ";cout<<endl;
//    cout<<"C";
//    for(auto x:C)cout<<x<<" ";cout<<endl;
    for (int i = 1; i <= q; i++) {
        printf("%lld\n", slove(k[i]));
    }
}
