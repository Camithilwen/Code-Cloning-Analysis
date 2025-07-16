#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[4],e,f;
    for(int i=0;i<4;i++){
        cin>>a[i];
    }
    
    cin>>f>>e;
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    if(e<f){
        swap(e,f);
    }
    cout<<a[0]+a[2]+a[1]+e<<endl;
    return 0;
}