#include <iostream>
using namespace std;
int main(void){
    int a,b;
    cin>>a>>b;
    if (a<b){
        int tmp =a;
        a=b;b=tmp;
    }
    int ans = a;
    a--;
    if (a<b){
        int tmp =a;
        a=b;b=tmp;
    }
    ans+=a;
    cout<<ans;
}
