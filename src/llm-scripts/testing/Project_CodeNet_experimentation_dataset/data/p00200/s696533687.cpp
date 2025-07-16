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
 #include<queue>
 #include<deque>
 #include<functional>
 #include<utility>
 
 using namespace std;
 
 const int MAX_V=100+5;
 const int INF=100000000;

 int main()
 {
   int graph[2][MAX_V][MAX_V];
   int path,V;
   while(cin>>path>>V&&(path||V))
   {
     for(int m=0;m<2;m++)
     {
       for(int i=0;i<V;i++)
       {
         for(int j=0;j<V;j++)
         {
           if(i==j) graph[m][i][j]=0;
           else graph[m][i][j]=INF;        
         }       
       }        
     }  
     while(path--)
     {
       int p,q;
       int cost,time;
       cin>>p>>q>>cost>>time;
       graph[0][p-1][q-1]=cost;
       graph[1][p-1][q-1]=time;     
       graph[0][q-1][p-1]=cost;
       graph[1][q-1][p-1]=time;         
     }                       
     for(int m=0;m<2;m++)
     {
       for(int k=0;k<V;k++)
       {
         for(int i=0;i<V;i++)
         {
           for(int j=0;j<V;j++)
           {
             graph[m][i][j]=min(graph[m][i][j],graph[m][i][k]+graph[m][k][j]);        
           }        
         }          
       }        
     }     
     int que;
     cin>>que;
     while(que--)
     {
       int start,end,type;
       cin>>start>>end>>type;
       cout<<graph[type][start-1][end-1]<<endl;           
     }
   }
   //while(1);
   return 0;
 }

 