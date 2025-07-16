#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

signed main(){
    int MOD = pow(10,9)+7;

    int H, W, K; cin>>H>>W>>K;
    if(W==1){
        cout<<1<<endl;
        return 0;
    }


    // 一列における棒の組み合わせをbit全探索で先に作っておく
    // [[],[0],[1],[0,2],...]
    // これの意味は0: 0-1の間, 1: 1-2の間に棒をおく、という感じである。
    
    vector<vector<int>> combi_list;
    for(int i=0;i< (1<<(W-1));i++){
        bitset<7> s(i);
        vec_int temp_combi;
        for(int i=0;i<W-1;i++){
            if(s[i]==1){
                temp_combi.push_back(i);
            }
        }
        // 作ったものが合法かをチェックする
        int prev=-100;
        int flag = 0;
        for(auto a: temp_combi){
            if(a-prev==1){
                flag=1;
                break;
            }
            prev=a;
        }
        if(flag==1)continue;

        combi_list.push_back(temp_combi);

    }
    /*
    for(auto aa: combi_list){
        cout<<"aa"<<endl;
        for(auto bb: aa){
            cout<<bb<<endl;
        }
    }
    */


    int DP[H+1][W];
    rep(i,H+1){
        rep(j,W){
            DP[i][j]=0;
        }
    }
    DP[0][0] = 1;

    for(int i=1;i<H+1;i++){
        for(int j=0;j<W;j++){
            // 最初にそのまま落ちてくるパターン
            int pattern = 0;
            for(auto aa: combi_list){
                int flag = 1;
                for(auto bb: aa){
                    if(bb==j||bb==j-1){
                        flag=0;
                        break;
                    }
                }
                if(flag==0)continue;
                pattern++;
            }
            DP[i][j] += DP[i-1][j]*pattern;

            // 一個左の棒から落ちてくるパターン
            pattern = 0;
            for(auto aa: combi_list){
                int flag = 0;
                for(auto bb: aa){
                    if(bb==j-1){
                        flag=1;
                        break;
                    }
                }
                if(flag==0)continue;
                pattern++;
            }
            if(j>0){
                DP[i][j] += DP[i-1][j-1]*pattern;
            }
            // 一個右の棒から落ちてくるパターン
            pattern = 0;
            for(auto aa: combi_list){
                int flag = 0;
                for(auto bb: aa){
                    if(bb==j){
                        flag=1;
                        break;
                    }
                }
                if(flag==0)continue;
                pattern++;
            }
            if(j<W-1){
                DP[i][j] += DP[i-1][j+1]*pattern;
            }

            DP[i][j] = DP[i][j]%MOD;
        }
    }

    cout<<DP[H][K-1]<<endl;





    return 0;
}