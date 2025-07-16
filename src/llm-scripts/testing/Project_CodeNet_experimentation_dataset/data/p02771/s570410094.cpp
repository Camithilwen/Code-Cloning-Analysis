#include<iostream>
#include<math.h>
using namespace std;

int main(){
    long long a,b,c,d=0,e=0;
    cin>>a>>b>>c;
    if(a==b && b==c || a!=b && b!=c && a!=c){cout<<"No";return 0;}
    else{cout<<"Yes";}
    return 0;
}
