// ref: https://img.atcoder.jp/abc113/editorial.pdf
// ref: https://atcoder.jp/contests/abc113/submissions/3540482


//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;

//---

template <typename T>
inline void print(const T& rhs){ std::cout<<" = "<<rhs<<std::endl; }
template <typename T>
inline void print(const std::vector<T>& rhs){
    std::cout<<" = [ ";
    for(uint i=0; i<rhs.size(); ++i){ std::cout<<rhs[i]<<' '; }
    std::cout<<"]"<<std::endl;
}
template <typename T>
inline void print(const std::vector<std::vector<T>>& rhs){
    std::cout<<" = "<<std::endl;
    std::cout<<"[[ ";
    for(uint p=0; p<rhs.size(); ++p){
        if(p!=0){ std::cout<<" [ "; }
        for(uint q=0; q<rhs[p].size(); ++q){
            std::cout<<rhs[p][q]<<' ';
        }
        if(p!=rhs.size()-1){ std::cout<<"]"<<std::endl; }
    }
    std::cout<<"]]"<<std::endl;
}
template <typename TL, typename TR>
inline void print(const std::vector<std::pair<TR,TL>>& rhs){
    std::cout<<" = [";
    uint i=0;
    for(; i<rhs.size()-1; ++i){ std::cout<<"[f: "<<rhs[i].first<<", s: "<<rhs[i].second<<"], "; }
    std::cout<<"[f: "<<rhs[i].first<<", s: "<<rhs[i].second<<"]]" << endl;
}
#define printn(var) {printf("%s", #var);print(var);}
#define printn_all(var) {printf("%s(%d): ", __func__, __LINE__);printf("%s", #var);print(var);}

//---

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    const int mod = 1000000007;
    
    int H, W, K; cin >> H >> W >> K;
    vector<vector<int>> dp(H+1, vector<int>(W, 0)); dp[0][0] = 1;
    
    for(int hi=0; hi<H; ++hi){
        for(int wi=0; wi<W; ++wi){
            for(int ls=0; ls< 1<<(W-1); ++ls){ // lines: ls
                
                bool isConnected=false; // check if the two horizontal lines are connected.
                for(int i=0; i<W-2; ++i){
                    if( (ls>>i)&1 && (ls>>(i+1))&1 ){ isConnected=true; break; }
                }
                if(isConnected){ continue; }
                
                if( wi>=1 && (ls>>(wi-1))&1 ){
                    dp[hi+1][wi-1] += dp[hi][wi];
                    dp[hi+1][wi-1] %= mod;
                }else if( wi<=W-2 && (ls>>wi)&1 ){
                    dp[hi+1][wi+1] += dp[hi][wi];
                    dp[hi+1][wi+1] %= mod;
                }else{
                    dp[hi+1][wi+0] += dp[hi][wi];
                    dp[hi+1][wi+0] %= mod;
                }
            }
        }
    }
    cout << dp[H][K-1] << endl;
    
    return 0;
}
