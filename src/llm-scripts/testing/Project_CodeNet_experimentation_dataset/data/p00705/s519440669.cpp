#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n, q;
  while(true){
    cin >> n >> q;
    if(n == 0)
      break;

    int m;
    vector< vector<int> > sch(n, vector<int>(101, 0));
    for(int i=0; i<n; i++){
      cin >> m;
      for(int j=0; j<m; j++){
        int temp;
        cin >> temp;
        sch[i][temp] = 1;
      }
    }

    int ans, nmax = 0;
    for(int i=0; i<101; i++){
      int sum = 0;
      for(int j=0; j<n; j++){
        sum += sch[j][i];
          }
      if(sum > nmax){
        ans = i;
        nmax = sum;
      }
    }
    
    if(nmax < q)
      ans = 0;
    cout << ans << endl;
  }
  
  return 0;
}