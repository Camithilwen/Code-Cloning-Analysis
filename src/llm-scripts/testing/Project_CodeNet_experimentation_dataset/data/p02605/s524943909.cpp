#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define TO_STRING(VariableName) # VariableName
#define LOG(x) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<endl;
#define LOG2(x,y) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<endl;
#define LOG3(x,y,z) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;
#define LOG4(w,x,y,z) if(DEBUG)cout<<TO_STRING(w)<<"="<<w<<" "<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

lli ans = INF;
const lli ssize = 400100;

void calc(vector<set<lli>> &lef,vector<set<lli>> &rig){
    REP(i,0,ssize){
        if(rig.size()==0)continue;
        for(auto e:lef[i]){
            auto itr = rig[i].upper_bound(e);
            if(itr==rig[i].end())break;
            LOG3(ans,(*itr),e);
            chmin(ans,(*itr)-e);
        }
    }
}


void func(long long N, std::vector<long long> X, std::vector<long long> Y, std::vector<std::string> U){

    {
    //LR combination
        vector<set<lli>> lef(ssize),rig(ssize);
        REP(i,0,N){
            if(U[i]=="R")lef[Y[i]].insert(X[i]);
            else if(U[i]=="L")rig[Y[i]].insert(X[i]);
        }
        calc(lef,rig);
    }

    {
    //UD combination
        vector<set<lli>> lef(ssize),rig(ssize);
        REP(i,0,N){
            if(U[i]=="U")lef[X[i]].insert(Y[i]);
            else if(U[i]=="D")rig[X[i]].insert(Y[i]);
        }
        calc(lef,rig);
    }

    {
        //y=x+b
        {
        //LU combination
            vector<set<lli>> lef(ssize),rig(ssize);
            REP(i,0,N){
                if(U[i]=="U")lef[X[i]-Y[i]+ssize/2].insert(X[i]*2);
                else if(U[i]=="L")rig[X[i]-Y[i]+ssize/2].insert(X[i]*2);
            }
            calc(lef,rig);
        }

        {
        //RD combination
            vector<set<lli>> lef(ssize),rig(ssize);
            REP(i,0,N){
                if(U[i]=="R")lef[X[i]-Y[i]+ssize/2].insert(X[i]*2);
                else if(U[i]=="D")rig[X[i]-Y[i]+ssize/2].insert(X[i]*2);
            }
            calc(lef,rig);
        }
    }
    
    {
        //y=-x+b
        {
        //LD combination
            vector<set<lli>> lef(ssize),rig(ssize);
            REP(i,0,N){
                if(U[i]=="D")lef[X[i]+Y[i]].insert(X[i]*2);
                else if(U[i]=="L")rig[X[i]+Y[i]].insert(X[i]*2);
            }
            calc(lef,rig);
        }

        {
        //RU combination
            vector<set<lli>> lef(ssize),rig(ssize);
            REP(i,0,N){
                if(U[i]=="R")lef[X[i]+Y[i]].insert(X[i]*2);
                else if(U[i]=="U")rig[X[i]+Y[i]].insert(X[i]*2);
            }
            calc(lef,rig);
        }
    }


    if(ans==INF){
        cout<<"SAFE"<<endl;
    }
    else{
        cout<<ans*5<<endl;
    }

}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    std::vector<long long> X(N);
    std::vector<long long> Y(N);
    std::vector<std::string> U(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&X[i]);
        scanf("%lld",&Y[i]);
        std::cin >> U[i];
    }
    func(N, std::move(X), std::move(Y), std::move(U));
    return 0;
}
