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

void func(long long N, std::string S, long long Q, std::vector<long long> k){

    lli d=0,m=0,dm=0;

    REP(j,0,Q){
        lli ans = 0;
        d=0,m=0,dm=0;
        REP(i,0,N){
            if(S[i]=='D')d++;
            if(S[i]=='M'){
                m++;
                dm+= d;
            }
            if(S[i]=='C')ans += dm;

            if(i<k[j]-1)continue;
            if(S[i-k[j]+1]=='D'){
                    dm -= m;
                    d--;
            }
            if(S[i-k[j]+1]=='M'){
                    m--;
            }
        }
        cout<<ans<<endl;
    }


}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    std::string S;
    std::cin >> S;
    long long Q;
    scanf("%lld",&Q);
    std::vector<long long> k(Q-1-0+1);
    for(int i = 0 ; i < Q-1-0+1 ; i++){
        scanf("%lld",&k[i]);
    }
    func(N, S, Q, std::move(k));
    return 0;
}
