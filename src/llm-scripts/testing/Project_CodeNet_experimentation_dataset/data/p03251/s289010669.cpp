#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
   int x, y, n, m, xi, yi, xmax=-100, ymin=100;
   cin>>n>>m>>x>>y;
   for (int i = 0; i < n; i++)
   {
       cin>>xi;
       xmax = max(xmax, xi);
   }
   for (int i = 0; i < m; i++)
   {
       cin>>yi;
       ymin = min(ymin, yi);
   }
   if(max(x,xmax) < min(y,ymin)){
       cout<<"No War";
   }
   else
   {
       cout<<"War";
   }
   
   
   
   return 0;
}
