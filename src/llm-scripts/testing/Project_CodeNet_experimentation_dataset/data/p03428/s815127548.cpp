#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=2003,INF=10000;

int main(){
    
    int N;cin>>N;
    vector<pair<double,double>> S(N);
    for(int i=0;i<N;i++){
        cin>>S[i].first>>S[i].second;
    }
    
    for(int i=0;i<N;i++){
        double a1=0,a2=M_PI,b1=M_PI,b2=M_PI*2.0;
        double ans=0.0;
        for(int j=0;j<N;j++){
            if(i==j) continue;
            if(S[i].first==S[j].first){
                if(S[i].second<S[j].second){
                    a1=0.0;
                    a2=0.0;
                }else{
                    b1=M_PI*2.0;
                    b2=M_PI*2.0;
                }
            }else if(S[i].first>S[j].first){
                if(S[i].second==S[j].second){
                    a2=min(a2,M_PI/2.0);
                    b1=max(b1,M_PI*1.5);
                }else if(S[i].second>S[j].second){
                    double x=S[i].first-S[j].first,y=S[i].second-S[j].second;
                    double a=-x/y;
                    a2=min(a2,atan(a)+M_PI);
                    b1=max(b1,atan(a)+M_PI*2.0);
                }else if(S[i].second<S[j].second){
                    double x=S[i].first-S[j].first,y=S[i].second-S[j].second;
                    double a=-x/y;
                    a2=min(a2,atan(a));
                    b1=max(b1,atan(a)+M_PI);
                }
            }else if(S[i].first<S[j].first){
                if(S[i].second==S[j].second){
                    a1=max(a1,M_PI/2.0);
                    b2=min(b2,M_PI*1.5);
                }else if(S[i].second>S[j].second){
                    double x=S[i].first-S[j].first,y=S[i].second-S[j].second;
                    double a=-x/y;
                    a1=max(a1,atan(a));
                    b2=min(b2,atan(a)+M_PI);
                }else if(S[i].second<S[j].second){
                    double x=S[i].first-S[j].first,y=S[i].second-S[j].second;
                    double a=-x/y;
                    a1=max(a1,atan(a)+M_PI);
                    b2=min(b2,atan(a)+M_PI*2.0);
                }
            }
        }
        if(a1<a2) ans+=(a2-a1)/(M_PI*2.0);
        if(b1<b2) ans+=(b2-b1)/(M_PI*2.0);
        cout<<setprecision(15)<<ans<<endl;
    }
}
