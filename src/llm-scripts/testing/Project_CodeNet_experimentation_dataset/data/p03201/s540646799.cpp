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
   int N;
   cin >> N;
   map<int,int> M;
   vector<int> A(N);
   for (int i = 0; i < N; i++)
   {
      cin >> A[i];
      M[A[i]]++;
   }
   sort(A.begin(),A.end());
   A.erase(unique(A.begin(),A.end()),A.end());
   int size = A.size();
   int ind = size-1;
   long long ans=0;
   for(long long offset = (1LL<<31); offset > 1; offset /=2){
      while(ind>=0&&A[ind]*2>=offset){
         int cur = A[ind];
         int partner = offset-A[ind];
         if(cur == partner){
            int pair= M[cur]/2;
            ans += pair;
            M[cur]-= pair*2;
         }
         else{
            int pair= min(M[cur],M[partner]);
            ans += pair;
            M[cur]-=pair;
            M[partner]-=pair;
         }
         ind--;
      }
   }
   cout << ans << endl;
   return 0;
}
