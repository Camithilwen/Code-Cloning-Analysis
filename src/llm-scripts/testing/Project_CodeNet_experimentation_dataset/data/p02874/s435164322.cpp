#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;

vector<vector<int>> Q(N, vector<int>(2));
for(int i=0;i<N;i++){
  int l,r;
  cin>>l>>r;
  Q[i][0]=l;
  Q[i][1]=r;
}

// 左側の順にソート
sort(Q.begin(),Q.end());

vector<int> A(N), B(N);
// A→１回目のコンテストの右側
// A[i]→i個目まで１回目のコンテストで出題
A[0] = Q[0][1];
for(int i=1;i<N;i++){
  A[i]= min(A[i-1],Q[i][1]);
}
// B→２回目のコンテストの右側
// B[i]→i個目まで１回目のコンテストで出題
B[N-1]=Q[N-1][1];
for(int i=N-2;i>=0;i--){
  B[i]= min(B[i+1],Q[i][1]);
}


int ans=0;

for(int i=0;i<N-1;i++){
  //cout<<A[i]<<" "<<Q[i][0]<<" "<<B[i+1]<<" "<<Q[N-1][0]<<endl;;
  ans = max(ans, max(0,A[i]-Q[i][0]+1)+max(0,B[i+1]-Q[N-1][0]+1));
  ans = max(ans, max(0,A[N-1]-Q[N-1][0]+1)+max(0,Q[i][1]-Q[i][0]+1));
//cout<<ans<<endl;
}
cout<<ans<<endl;


}
