#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string S;
vector<vector<int>> color;

void hantei(int i){
  if(S[i]=='R'){
    color[0][i]++;
  }
  else if(S[i]=='G'){
    color[1][i]++;
  }
  else if(S[i]=='B'){
    color[2][i]++;
  }
}

int main(){
  int N;
  cin >> N >> S;
  vector<vector<int>> c(3,vector<int>(N,0));
  color=c;
  ll ans=0;
  hantei(0);
  for(int i=0;i<N;i++){
    color[0][i]=color[0][i-1];
    color[1][i]=color[1][i-1];
    color[2][i]=color[2][i-1];
    hantei(i);
  }
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      if(S[i]==S[j]){
        continue;
      }
      if((S[i]=='R' && S[j]=='G') || (S[i]=='G' && S[j]=='R')){
        ans+=color[2][N-1]-color[2][j];
        if(i+2*(j-i)<N && S[i+2*(j-i)]=='B'){
          ans--;
        }
      }
      else if((S[i]=='G' && S[j]=='B') || (S[i]=='B' && S[j]=='G')){
        ans+=color[0][N-1]-color[0][j];
        if(i+2*(j-i)<N && S[i+2*(j-i)]=='R'){
          ans--;
        }
      }
      else if((S[i]=='B' && S[j]=='R') || (S[i]=='R' && S[j]=='B')){
        ans+=color[1][N-1]-color[1][j];
        if(i+2*(j-i)<N && S[i+2*(j-i)]=='G'){
          ans--;
        }
      }
    }
  }
  cout << ans << endl;
}