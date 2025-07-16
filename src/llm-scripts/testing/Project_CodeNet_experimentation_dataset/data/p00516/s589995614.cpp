#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#include <iterator>
#define FI first
#define SE second
#define PF push_front
#define PB push_back
#define POF pop_front
#define POB pop_back
#define MA make_pair
#define ll long long
#define VE vector<int>
#define VP vector<pair<int,int> >
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
using namespace std;
//
const int INF=1e9+7;
const int mod=1e9+7;
//
int N,M,B;
int A[1000];
int C[1000];
int main(){
  cin>>N>>M;
  FOR(i,0,N){
    cin>>A[i];
  }
  FOR(i,0,M){
    cin>>B;
    int j=0;
    while(B<A[j]){
      j++;
    }
    C[j]++;
  }
  int M=0,ans;
  FOR(i,0,N){
    if(M<C[i]){
      M=C[i];
      ans=i+1;
    }
  }
  cout<<ans<<endl;
  return 0;
}
