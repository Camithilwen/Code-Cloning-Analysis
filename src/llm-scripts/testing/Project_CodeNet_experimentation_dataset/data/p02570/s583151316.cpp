#include <iostream>

using namespace std;

int main()
{
  int D,T,S;
  cin>>D>>T>>S;
double  t=(double)D/S;
  if(t<=T){
    cout<<"Yes"<<endl;
  }
  else {
    cout<<"No"<<endl;
  }
    return 0;
}
