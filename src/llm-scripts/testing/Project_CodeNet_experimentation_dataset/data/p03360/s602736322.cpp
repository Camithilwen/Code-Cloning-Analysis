#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
  	sort(a,a+3);
    int k;
    cin>>k;
    cout<<a[0]+a[1]+(a[2]<<k);
}
