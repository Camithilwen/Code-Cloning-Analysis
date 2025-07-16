#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>
#include <unordered_map>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';


using namespace std;

ll cutter[]={1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288};

bool cut(int in, ll index){
    if(in/cutter[index]%2==0) return false;
    else return true;
}

int main(void){
    ll N;
    unordered_map<string, ll> kosuL;
    unordered_map<string, ll> kosuR;
    ll count=0;
    string S;
    cin>>N>>S;
    string SL="", SR="";
    rep(i, N){
        SL+=S[i];
        SR+=S[2*N-1-i];
    }
    ll ZENTAN_MAX=pow(2, N);
    rep(i, ZENTAN_MAX){
        string str="", str2="";
        rep(j, N) if(cut(i, j)) str+=SL[j]; else str2+=SL[j];
        //cout<<str<<sp<<str2<<endl;
        string ansstr=str+"#"+str2;
        kosuL[ansstr]++;
    }
    rep(i, ZENTAN_MAX){
        string str="", str2="";
        rep(j, N) if(cut(i, j)) str+=SR[j]; else str2+=SR[j];
        //cout<<str<<sp<<str2<<endl;
        string ansstr=str+"#"+str2;
        kosuR[ansstr]++;
    }
    for(auto itr : kosuR){
        count+=(itr.second)*kosuL[itr.first];
    }
    cout<<count<<endl;
    return 0;
}
