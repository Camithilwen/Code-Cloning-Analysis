#include <iostream>
using namespace std;

int main(){
    int a[6];
    int sum=0;
    for(int i=0;i<6;i++){
        cin>>a[i];
        sum+=a[i];
    }
    
    int min=100;
    for(int j=0;j<4;j++){
        if(min>a[j])min=a[j];
    }
   
    sum=sum-min;
    
    if(a[4]>a[5])sum=sum-a[5];
    else sum=sum-a[4];
    
    cout<<sum<<endl;
}