#include <iostream>
 using namespace std ;
 int main()
 {
   int A, B, c, d, e;
   cin>>A;
   cin>>B;
   c =(A + B);
   d =(A - B);
   e =(A * B);
   if (c >= e&&c >= d)
   {
   cout<<c<<endl;
   }
else   if (e >= d&&e >= c)
   {
     cout<<e<<endl;
   }
  else  if (d >= e&&d >= c) 
   {
     cout<<d<<endl;
   }
   }