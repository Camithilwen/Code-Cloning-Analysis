#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    int remainder;
    bool vqrno=false;
    while(n!=0){
        remainder=n%10;
        if(remainder==7){
            vqrno=true;
            break;
        }
        else
            n/=10;
    }
    if(vqrno==true)
        puts("Yes");
    else
        puts("No");
}
