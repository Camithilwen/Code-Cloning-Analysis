#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include <iomanip>
#include <iostream>
using namespace std;
 
int main(){

    int A,B,ans=0;
    cin>>A>>B;

    for(int i=1;i<=3;i++){
        if(A==i)ans+=(4-i)*100000;
        if(B==i)ans+=(4-i)*100000;
    }

    if(A==1&&B==1)ans+=400000;
    
    cout <<ans<<endl;
    
    return 0;

}