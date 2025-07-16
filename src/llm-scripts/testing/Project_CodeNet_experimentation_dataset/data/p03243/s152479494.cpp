#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(){
    int n,m;
    cin >> n;
    int r1,r2,r3;
    for(int i=0; i<999;i++){
        m = n;
       r1 = (n%10);
       n-=r1;
       n/=10;
       r2 = (n%10);
       n-=r2;
       n/=10;
       r3 = (n%10);
       n-=r2;
       if( r1 == r2 && r1 == r3){
           break;
       }
       m++;
       n=m;
    }
    cout << r1 << r2 << r3 << endl;
}