#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
    if(n<3)
        cout<<0;
    else if (n%3==0)
        cout<<n/3;
    else if(n%3!=0){
        while(true){
            n++;
            if(n%3==0){
                cout<<n/3-1;
             break;
            }
        }
    }
   return 0;
   }