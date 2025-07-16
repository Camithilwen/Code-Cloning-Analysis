#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
int main(void){
   vector<int> w(10);
   vector<int> k(10);
   int sumw=0,sumk=0;
   
   for(int i=0;i<10;i++)cin>>w[i];
   for(int i=0;i<10;i++)cin>>k[i];
   
   sort(w.begin(),w.end());
   sort(k.begin(),k.end());
   
   for(int i=9;i>6;i--) {
       sumw+=w[i];
       sumk+=k[i];
   }
        
    cout<<sumw<<" "<<sumk<<endl;
    
    
    return 0;
}