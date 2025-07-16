#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int n, k;
   cin>>n>>k;
   vector<int> p(n);
   rep(i, n) cin>>p[i];

   vector<int> ki2(n);
   rep(i, n) ki2[i]=(p[i]+1);

   int sum=0;
   rep(i, k) sum+=ki2[i];
   int mx=0;
   for(int i=0; i+k-1<n; i++){
      mx=max(mx, sum);
      if(i+k<n) sum+= -ki2[i] +ki2[i+k];
   }

   double ans=(double)mx/2;
   cout<<std::setprecision(15)<<ans<<endl;
   return 0;
}
