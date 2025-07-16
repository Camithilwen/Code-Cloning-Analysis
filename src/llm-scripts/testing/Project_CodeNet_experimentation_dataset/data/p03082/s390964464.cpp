#include <bits/stdc++.h>

using namespace std;
#define _for(i,j,N) for(int i = (j);i < (N);i++)
#define _rep(i,j,N) for(int i = (j);i <= (N);i++)
#define ALL(x) x.begin(),x.end()
#define LL long long

int N,X;
const int maxn = 201;
const int maxm = 100005;
const int modu = 1e9+7;
int dp[2][maxm];

vector<int> vi;

int mult(int a,int b){
    LL c = a;c *= b;c %= modu;return c;
}

int add(int a,int b){
    LL c = a;c += b;c %= modu;return c;
}


int get_int(){int x;scanf("%d",&x);return x;}
double get_double(){double x;scanf("%lf",&x);return x;}
long long get_long(){long long x;scanf("%lld",&x);return x;}

void init(){
    vi.clear();
    _for(i,0,maxm) dp[0][i] = 0;
}

int main(){
    scanf("%d %d",&N,&X);
    init();
    _for(i,0,N){
        int s = get_int();
        vi.push_back(s);
    }
    sort(ALL(vi),greater<int>());
    dp[0][X] = 1;
    int t = 0;

    _for(i,0,N){
        _for(j,0,maxm){
            dp[t^1][j] = 0;
        }

        _for(j,0,maxm){
            if(dp[t][j]){
                //printf("%d\n",j);
                dp[t^1][j%vi[i]] = add(dp[t][j],dp[t^1][j%vi[i]]);
                dp[t^1][j] = add(dp[t^1][j],mult(dp[t][j],(N-i-1)));
            }
        }
        t= t^1;
    }

    int ans = 0;

    _for(i,1,maxm){
        if(dp[t][i] > 0){
            //printf("%d %d\n",i,dp[t][i]);
            ans = add(ans,mult(i,dp[t][i]));
        }
    }
    printf("%d\n",ans);
}
