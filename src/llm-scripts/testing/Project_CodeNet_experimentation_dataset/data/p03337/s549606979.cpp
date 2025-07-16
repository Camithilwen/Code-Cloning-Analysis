#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main (void){
    int a, b;
    int i, j, k;
    cin >> a >> b;
    i = a + b;
    j = a - b;
    k = a * b;

   if(i < j){
       if(j < k){
           cout << k << endl;
       }else{
           cout << j << endl;
       }
   }else if(j < i){
       if(i < k){
           cout << k << endl;
       }else{
           cout << i << endl;
       }
   }else if(k < i){
       if(i < j){
           cout << j << endl;
       }else{
           cout << i << endl;
       }
   }else{
       cout << 0 << endl;
   }

    return 0;
}
