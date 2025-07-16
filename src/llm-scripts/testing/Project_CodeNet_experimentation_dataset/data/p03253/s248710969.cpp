#include <iostream>
#include <map>
#include <math.h>
#include <vector>
using namespace std;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

int main(){
    int N,M;
    cin >> N >> M;
    int r= 2;
    int count=0;//素因数の数
    map<long long  ,int  > insuu;
    vector<int > prime;
    COMinit();
    //因数分解部
    int pM=M;
    while(M>1){
        if(M%r!=0){//割り切れないなら次の因数を検索
            while(true){
                if(r==2){
                    r++;
                }else{
                    r+=2;
                }
                if(M%r==0){
                    break;
                }
                if(r>sqrt(pM)){
                    prime.push_back(M);
                    insuu[M]++;
                    M=1;
                    break;
                }
            }
        }else{
            M=M/r;
            if(insuu[r]<1){
                prime.push_back(r);
            }
            count++;
            insuu[r]++;
        }   
    }
    //出力計算部
    long long ans=1;
    for(auto v :prime){
        ans*=fac[N+insuu[v]-1]*((finv[insuu[v]])*finv[N-1]%MOD)%MOD;
        ans=ans%MOD;
    }
    cout << ans << endl;
    return 0;
}