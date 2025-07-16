#include<iostream>
using namespace std;
int main()
{
    int N;
   cin>>N;
   for(int i=40000;i>=1;i--)
   {
       if(i*i<=N)
       {
           cout<<i*i<<endl;
           break;
       }
   }
}
