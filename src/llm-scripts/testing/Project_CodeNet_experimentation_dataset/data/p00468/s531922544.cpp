#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int n,m;
  bool f[500][500];
  bool ans[500];
  int a,b;

  for(;;){
    cin >> n >> m;
    if(!n && !m)break;

    for(int i=0;i<n;i++){
      ans[i] = false;
      for(int j=0;j<n;j++)f[i][j] = false;
    }

    while(m--){
      cin >> a >> b;
      a--;
      b--;
      f[a][b] = true;
      f[b][a] = true;
      if(!a)ans[b] = true;
      if(!b)ans[a] = true;
    }

    for(int i=0;i<n;i++)
      if(f[0][i])
	for(int j=0;j<n;j++)ans[j] |= f[i][j];

    cout << count(ans+1,ans+n,true) << endl;
  }
}