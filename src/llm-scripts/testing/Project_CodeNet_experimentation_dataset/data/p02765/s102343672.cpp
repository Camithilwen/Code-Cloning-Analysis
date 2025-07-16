#include <iostream>
using namespace std;
int Rates(int A){
     if (A>=10){
          return 0;
     }else{
          return 100*(10-A);
     }
}
int main(){
     int N,R;
     cin >>N>>R;
     cout <<R+Rates(N)<<endl;
}
