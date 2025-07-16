#include<iostream>
using namespace std ;

int main()
{
  string S ;
  cin>>S ;
  
  int SIZE=S.size() ;
  if(SIZE==2) cout<<S<<endl ;
  else for(int i=SIZE-1;i>=0;i--) cout<<S.at(i) ;
  
  return 0 ;
}