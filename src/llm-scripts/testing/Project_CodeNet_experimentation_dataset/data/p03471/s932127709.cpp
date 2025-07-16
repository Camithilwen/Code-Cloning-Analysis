#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,y;
    cin>>n>>y;
    long long f=y/10000;
    f(i,0,f+1){
        f(j,0,n-i+1){
            if(10000*i+5000*j+1000*(n-j-i)==y){
                cout<<i<<" "<<j<<" "<<n-i-j<<endl;
                return 0; 
            }
        }
    }
    cout<<-1<<" "<<-1<<" "<<-1<<endl;
    return 0;
}