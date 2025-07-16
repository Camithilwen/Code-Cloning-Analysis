#include<iostream>
using namespace std;
int main(){
    int n,k,l,m,o;
    cin>>n;
    for(int i=3;i<=n;i++){
        k=i%10;
        l=i/1000;
        m=i/100%10;
        o=i/10%10;
        if(i%3==0){
            cout<<" "<<i;
        }else if(k==3 || l==3 || m==3 || o==3){
            cout<<" "<<i;
        }
    }
    cout<<endl;
    return 0;
}