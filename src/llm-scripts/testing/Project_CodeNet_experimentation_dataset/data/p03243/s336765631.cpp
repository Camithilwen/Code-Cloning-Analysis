#include <iostream>
#include <vector>
#include <cstdlib>  
#include <algorithm>
#include <string>

using namespace std;
 
int main() {
    int n;cin>>n;
    for(int i = n;i<10000;i++){
       string str = std::to_string(i);
       if(str[0] == str[1]&&str[1] == str[2]){
         cout<<i;
         return 0;
         break;
       }
    }
      
    return 0;
}