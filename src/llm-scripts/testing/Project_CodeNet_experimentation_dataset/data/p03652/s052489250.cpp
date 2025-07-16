#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <iomanip>
#include <cassert>

using namespace std;
typedef long long ll;

int main(){
   int N, M;
   cin >> N >> M;
   vector<int> pos(N,0);
   int favs[N][M];
   for(int i = 0 ; i <N; i++){
      for(int j = 0; j <M; j++){
         cin >> favs[i][j];
         favs[i][j]--;
      }
   }
   vector<bool> used(M,false);
   int ans = N;
   for(int j = 0 ; j < M; j++){
      vector<int> cnt(M,0);
      int target = 0;
      int m=0;
      for(int i = 0 ; i <N; i++){
         int f = favs[i][pos[i]];
         cnt[f]++;
         if(cnt[f]>m){
            m=cnt[f];
            target = f;
         }
      }
      // delete target
      //cout << m << " " << target << endl;
      used[target]=true;
      ans = min(m,ans);
      if(j!=M-1){
         for(int i = 0 ; i <N; i++){
            while(used[favs[i][pos[i]]]==true) pos[i]++; 
         }
      }
   }
   cout << ans << endl;
   return 0;
}
