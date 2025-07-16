#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
int main() {
    int N;
    cin>>N;
    vector<int>A(N+2);
    rep(i,0,N) cin>>A[i+1];
    int sum=0;
    rep(i,0,N+2){
      sum+=abs(A[i]-A[i+1]);
    }
    rep(i,0,N){
      int tmp=sum-abs(A[i+1]-A[i])-abs(A[i+1]-A[i+2])+abs(A[i]-A[i+2]);
      cout<<tmp<<endl;
    }
    return 0;
}