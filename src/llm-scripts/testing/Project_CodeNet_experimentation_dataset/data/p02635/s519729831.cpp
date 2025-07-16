#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
long double eps = 1e-6;
long double pi = acos(-1);

ll mod = 998244353;
template<typename T> void add(T &a,T b){a=(a+b)%mod;}
template<typename T> void sub(T &a,T b){a=(a+mod-b)%mod;}

int dp[333][333][333];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    string s;
    int k;
    cin>>s>>k;
    int n = s.size();
    int sum[n+1]={};
    int z = 0;
    int o = 0;
    for(int i=0;i<n;i++){
        if(s[i] == '0'){
            z++;
            sum[z+1] = sum[z];
        }
        else o++;
        sum[z+1] = o;
    }
    
    dp[0][0][0] = 1;
    for(int i=0;i<z;i++){
        for(int y=0;y<=min(k,o);y++){
            for(int j=sum[i];j<=min(o,sum[i]+k);j++){
                if(dp[i][j][y] == 0)continue;
                if(j-sum[i] > y)break;
                for(int p=max(j,sum[i+1]);p<=min(sum[i+1]+k,o);p++){
                    int ret = dp[i][j][y];
                    int cnt = y;
                    int dif = p - j;
                    dif -= sum[i+1] - sum[i];
                    dif = max(0,dif);
                    cnt += dif;
                    if(cnt <= k){
                        add(dp[i+1][p][cnt],ret);
                    }
                    else break;
                }
            }
        }
    }
    int ans = 0;
    for(int i=sum[z];i<=o;i++){
        for(int y=0;y<=min(o,k);y++){
            add(ans,dp[z][i][y]);
        }
    }
    cout << ans << endl;
}
