#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int N,M;
double x[100010];
ll K;
int a[100010];

vector<int> replace(vector<int> A,ll n){
    vector<int> B(N+1);
    for(int i=1;i<N;i++) B[i]=i;
    while(n>0){
        if(n&1){
            vector<int> C=B;
            for(int i=1;i<N;i++){
                B[i]=A[C[i]];
            }
        }

        vector<int> D=A;
        for(int i=1;i<N;i++){
            A[i]=D[D[i]];
        }
        n>>=1;
    }
    return B;
}

int main(){
  cin>>N;
  for(int i=0;i<N;i++) cin>>x[i];
  cin>>M>>K;
  for(int i=0;i<M;i++) cin>>a[i];

  double dif[N+1]={};
  for(int i=1;i<N;i++){
      dif[i]=x[i]-x[i-1];
  }

  vector<int> index(N+1);
  for(int i=1;i<N;i++) index[i]=i;
  for(int i=0;i<M;i++){
      swap(index[a[i]],index[a[i]-1]);
  }

  vector<int> A=replace(index,K);
  double ans[N+1]={};
  ans[0]=x[0];
  for(int i=1;i<N;i++){
      ans[i]=ans[i-1]+dif[A[i]];
  }
  for(int i=0;i<N;i++) cout<<fixed<<setprecision(10)<<ans[i]<<endl;

  return 0;
}
