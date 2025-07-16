// ref: https://img.atcoder.jp/arc093/editorial.pdf

//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
typedef int64_t int64;
typedef uint32_t uint;
typedef uint64_t uint64;
using namespace std;

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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int K=50;
    int A, B; cin >> A >> B; --A; --B;
    vector<string> vS(100);
    for(int i=0; i<K;   ++i){ vS[i] = string(100, '#'); }
    for(int i=K; i<2*K; ++i){ vS[i] = string(100, '.'); }
    
    int cnt=0;
    for(int i=0; i<K-1; i+=2){
        if(cnt >= A){ break; }
        for(int si=0; si<2*K; si+=2){
            if(cnt >= A){ break; }
            
            vS[i][si] = '.'; ++cnt;
        }
    }
    cnt=0;
    for(int i=K+1; i<2*K; i+=2){
        if(cnt >= B){ break; }
        for(int si=0; si<2*K; si+=2){
            if(cnt >= B){ break; }
            
            vS[i][si] = '#'; ++cnt;
        }
    }
    
    cout << 2*K << ' ' << 2*K << endl;
    for(int i=0; i<2*K; ++i){
        cout << vS[i] << endl;
    }
    
    return 0;
}