#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(),(a).end()
#define MOD 100000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<double,string> P;
const int INF=1e9;
bool comp(P a,P b){
      if(a.first!=b.first)return a.first>b.first;
      int l=min(a.second.size(),b.second.size());
      REP(i,l){
            if(a.second[i]!=b.second[i])return a.second[i]<b.second[i];
      }
      return a.second.size()<b.second.size();
}
int main(){
      int n,p,a,b,c,d,e,f,s,m;
      while(cin>>n&&n){
            vector<P> V;
            string l;
            REP(i,n){
                  cin>>l>>p>>a>>b>>c>>d>>e>>f>>s>>m;
                  if(m==1){
                        V.PB(P((double)(s*f-p)/(a+b+c+d+e),l));
                  }else{
                        V.PB(P((double)(s*f*m-p)/(a+b+c+(d+e)*m),l));
                  }
            }
            sort(ALL(V),comp);
            REP(i,V.size()){
                  cout<<V[i].second<<endl;
            }
            cout<<'#'<<endl;
      }
}