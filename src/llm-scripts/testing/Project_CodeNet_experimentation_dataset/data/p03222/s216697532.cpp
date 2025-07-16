#include<iostream>
#include<vector>
using namespace std;
const int MOD=1000000007;
void add(long long &a,long long b){a+=b;if(a>=MOD)a-=MOD;}

int H,W,K;
long long solve(){
    --K;
    vector<vector<long long> > dp(H+1,vector<long long>(W,0));
    dp[0][0]=1;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            for(int bit=0;bit<1<<(W-1);bit++){
                bool ok=true;
                for(int k=0;k<W-2;k++){
                    if((bit&(1<<k))&&(bit&(1<<(k+1)))) ok=false;
                }
                if(!ok)continue;
                int nj=j;
                if(bit&(1<<j))nj=j+1;
                else if(j>0&&(bit&(1<<(j-1))))nj=j-1;
                add(dp[i+1][nj],dp[i][j]);
            }
        }
    }
    return dp[H][K];
}

int main(){
    while(cin>>H>>W>>K)cout<<solve()<<endl;
}