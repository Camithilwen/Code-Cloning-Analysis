#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define vi vector<int>
#define vv vector<vi>
#define pb push_back
#define pi pair<int,int>
#define vp vector<pair<int,int> >
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define INF 100000000000
#define eps 1e-7
#define mod 1000000007
#define int ll
using namespace std;

int A[5*100000 + 10];
int S[5*100000 + 10];

vi idx[(1LL<<20)+10];
//idx[i]:S中の，iの存在するindexのリスト
int zero[5*100000 + 10];
//zero[i]:S中のi番目までに，いくつ０があるか
int dp[5*100000+10];
//dp[i]:i番目まで見たときの場合の数

signed main(void) {
    int N;
    cin>>N;
    S[0]=0;
    zero[0]=0;
    REP(i,1,N) {
        cin>>A[i];
        S[i] = S[i-1]^A[i];
        if (S[i] == 0) zero[i] = zero[i-1]+1;
        else zero[i] = zero[i-1];
        idx[S[i]].pb(i);
//        cerr<<S[i]<<"\t";
    }
//    cerr<<endl;
//    REP(i,1,N) cerr<<zero[i]<<"\t";
//    cerr<<endl;

    if (S[N] == 0) {
        //Sの右端が0のケース
        int ans = 0;
        REP(d,1,1LL<<20) {
//    REP(d,1,8) {
            //まず，dがSのなかにいくつあるのか確認
            int dnum = idx[d].size();
            if (dnum==0) continue;
            //0,d,0,...,d,0だから，必要なdp配列の数はdnum*2+1;
            dp[0]=1; //スタート→１通り
            int from_zero=1;
            int from_d=0;
            REP(i,1,dnum*2) {
                if (i==dnum*2) { //ラス１→絶対右端で止まらないといけないので１通り
                    dp[i] = from_d;
                } else if (i%2==0) { //iが偶数→現在地はd
                    //まず，行き先候補の0の数を計算
                    int znum = (zero[idx[d][i/2]]-zero[idx[d][i/2-1]]) % mod;
                    dp[i] = znum * from_d % mod;
                    from_zero += dp[i];
                    from_zero %= mod;
                } else { //iが奇数→現在地は0
                    dp[i] = from_zero;
                    from_d += dp[i];
                    from_d %= mod;
                }
//            cerr<<dp[i]<<"\t";
            }
//        cerr<<endl;
//        cerr<<"d="<<d<<"の時："<<dp[dnum*2]<<endl;
            ans += dp[dnum*2];
            ans %= mod;
        }
        //d=0でpartitionする場合→2^(0の総数-1)通り
        int pow2 = 1;
        REP(j,1,zero[N]-1) {
            pow2 *= 2;
            pow2 %= mod;
        }
        cout << (ans + pow2) % mod << endl;
    } else { //Sの右端が0でない→それをdとしてやるだけ
        int d=S[N];
        //まず，dがSのなかにいくつあるのか確認
        int dnum = idx[d].size();
        //0,d,0,...,0,dだから，必要なdp配列の数はdnum*2;
        dp[0]=1; //スタート→１通り
        int from_zero=1;
        int from_d=0;
        REP(i,1,dnum*2-1) {
            if (i%2==0) { //iが偶数→現在地はd
                //まず，行き先候補の0の数を計算
                int znum = (zero[idx[d][i/2]]-zero[idx[d][i/2-1]]) % mod;
                dp[i] = (znum * from_d) % mod;
                from_zero += dp[i];
                from_zero %= mod;
            } else { //iが奇数→現在地は0
                dp[i] = from_zero;
                from_d += dp[i];
                from_d %= mod;
            }
//            cerr<<dp[i]<<"\t";
        }
//        cerr<<endl;
//        cerr<<"d="<<d<<"の時："<<dp[dnum*2]<<endl;
        cout << dp[dnum*2-1] % mod << endl;

    }



    return 0;
}