#include <bits/stdc++.h>

using namespace std;
#define _for(i,j,N) for(int i = (j);i < (N);i++)
#define _rep(i,j,N) for(int i = (j);i <= (N);i++)
#define ALL(x) x.begin(),x.end()

int get_int(){int x;scanf("%d",&x);return x;}

typedef long long ll;

const int mod = 998244353;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y) {return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y) {return x-y>=0?x-y:x-y+mod;}
int sq(int x){return 1ll*x*x%mod;}
int pows(int a,int b){return b == 0?1:(b&1?mul(a,sq(pows(a,b/2))):sq(pows(a,b/2)));}


const int maxn = 305;
int cnt[maxn*maxn];
int cnt2[maxn*maxn];

int sum;
int N;





void cal(int n,vector<int> &vi){
    cnt[0] = 1;
    cnt2[0] = 1;
    _for(i,0,N){
        int l = vi[i];
        for(int j = sum;j>=0;j--){
            cnt2[j] = add(cnt2[j],cnt2[j]);
            if(j-l >= 0) {
                cnt[j] = add(cnt[j],cnt[j-l]);
                cnt2[j] = add(cnt2[j],cnt2[j-l]);
            }
        }
    }
}

int main()
{
    vector<int> vi;
    N = get_int();
    _for(i,0,N){
        int num = get_int();
        sum += num;
        vi.push_back(num);
    }
    sort(ALL(vi));

    int ans = pows(3,N);
    //printf("all:%d\n",ans);

    cal(N,vi);
    //_rep(i,0,sum) printf("%d\n",cnt2[i]);

    _rep(i,(sum+1)/2,sum){
        ans = sub(ans,mul(3,cnt2[i]));
        //printf("%d\n",cnt2[i]);
    }

    if(!(sum&1)){
        ans = add(ans,mul(cnt[sum/2],3));
    }

     printf("%d\n",ans);
    return 0;
}
