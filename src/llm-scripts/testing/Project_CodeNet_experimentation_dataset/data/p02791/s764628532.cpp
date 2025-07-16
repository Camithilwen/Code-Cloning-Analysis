#include<bits/stdc++.h>
using namespace std;
 int main()
 {
     int x,y,i,j,n;
     deque<int >v;
     cin >> n;
     for(i = 0 ;i<n ;i++)
     {
         cin >> x;
         deque<int >:: iterator it;
         it = upper_bound(v.begin(),v.end(),x);
         if(v.begin()== it)
            v.push_front(x);
         else
            v[it -v.begin()]==x ;
     }
     cout<<v.size()<<endl;
 }
