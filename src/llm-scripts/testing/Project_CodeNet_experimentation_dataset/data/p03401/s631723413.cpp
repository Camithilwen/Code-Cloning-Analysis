#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793


   
int main(){
   int n;
   cin >> n;
   VI a(n+2);
   a[0]=0;
   a[n+1]=0;
   for(int i=1;i<=n;i++){
      cin >> a.at(i);
   }
   ll ro=0;
   rep(i,n+2){
      ro+=abs(a[i]-a[i+1]);
   }
   for(int i=1;i<=n;i++){
      if((a[i]-a[i-1])*(a[i+1]-a[i])>=0){
         cout << ro << endl;
      }
      else{
         int z=min(abs(a[i]-a[i-1]),abs(a[i+1]-a[i]));
         cout << ro-2*z << endl;
      }
   }
}
    