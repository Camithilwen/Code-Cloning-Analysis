 
 #include<iostream>
 #include<stdio.h>
 #include<string>
 #include<math.h>
 #include<iomanip>
 #include<algorithm>
 #include<string.h>
 #include<cctype>
 #include<map>
 #include<set>
 #include<vector>
 #include<sstream>
 #include<stack>
 
 using namespace std;
  
 int main()
 {
   string a,b;
   while(getline(cin,a))
   {
     for(int shift=0;shift<26;shift++)
     {
       b="";
       for(int i=0;i<a.length();i++)
       {
         if(a[i]>='a'&&a[i]<='z')
         { 
           if(a[i]+shift>'z') b+=(a[i]+(shift-26));
           else b+=(a[i]+shift);
         }         
         else b+=a[i]; 
       }
       if(b.find("the")!=string::npos||b.find("this")!=string::npos||b.find("that")!=string::npos) break;
       else continue;
     }             
     cout<<b<<endl;
   }
   //while(1);      
   return 0;    
 }

 