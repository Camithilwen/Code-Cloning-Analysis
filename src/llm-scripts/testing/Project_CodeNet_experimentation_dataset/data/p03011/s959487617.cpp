#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int a,b,c,e=0,z,d,f,g;
    cin>>a>>b>>c;
    z=min((a+b),(b+c));
    z=min(z,(c+a));
    cout<<z;
    return 0;
}
