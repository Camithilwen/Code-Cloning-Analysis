#include <bits/stdc++.h>
using namespace std;
//#define MOD 1000000007
#define MOD 998244353
#define INF 1145141919810893364
//#define INF 810114514
#define PI 3.141592653589
typedef long long ll;
typedef pair<ll,ll> PP;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "0" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl
#define debug false
#define debug2 false

bool comp(pair<pair<int,int>,string> G,pair<pair<int,int>,string> H){
    int Ga=G.first.first;
    int Gb=G.first.second;
    int Ha=H.first.first;
    int Hb=H.first.second;
    
    if(Ga-Gb>=0 && Ha-Hb<0)return true;
    if(Ga-Gb<0 && Ha-Hb>=0)return false;
    
    if(Ga-Gb>=0 && Ha-Hb>=0){
        return Gb<Hb;
    }else{
        return Ga>Ha;
    }
}

signed main(void){
    int N;
    string S;
    vector<pair<pair<int,int>,string>> V;
    
    cin >> N;
    REP(i,N){
        cin >> S;
        int a=0,b=0;
        REP(j,S.size()){
            if(S[j]=='('){
                a++;
            }else{
                b++;
            }
        }
        V.push_back({{a,b},S});
    }
    
    sort(V.begin(),V.end(),comp);
    
    //REP(i,N){cout << V[i].second << endl;}
    
    
    int now=0;
    bool ok = true;
    REP(i,N){
        string S = V[i].second;
        REP(j,S.size()){
            if(S[j]=='('){
                now++;
            }else{
                now--;
            }
            if(now<0)ok=false;
        }
    }
    if(now!=0)ok = false;
    
    cout << (ok?"Yes":"No") << endl;
    
    return 0;
}


