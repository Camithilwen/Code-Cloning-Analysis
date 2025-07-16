#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define REP(i,n) for (int i=0;i<(n);i++)
#define ALL(a) (a).begin(),(a).end()
#define MOD 10000
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const ull B=100000007;
const int INF=1e9;
int main(){
      int n,a[3];
      cin>>n;
      REP(i,n)cin>>a[i];
      sort(a,a+n);
      REP(i,a[0]){
            bool f=true;
            REP(j,n)if(a[j]%(i+1)!=0)f=false;
            if(f)cout<<i+1<<endl;
      }
}