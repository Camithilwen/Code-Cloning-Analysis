#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,r;
    cin>>n>>r;
    
    if(n>=10){
        cout<<r<<endl;
    }else{
        cout<<r+1000-100*n<<endl;
    }
    return 0;
}
