#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    long long int ar=0;

    
    
    int temp[64];
    for(int i=0;i<64;i++){
        temp[i]=0;
    }
    for(int i=0;i<n;i++){
        cin>>ar;
        int j=0;
        while(ar>0){
            temp[j]+=ar%2;
            ar/=2;
            j++;
        }
    }
    long long int sum=0,tempsum=0,temp2;

    for(int i=0;i<63;i++){
        int k1=temp[i],k2=n-temp[i];
        // cout <<k1 << " " << k2 << endl;
        tempsum=k1;tempsum*=k2;
        if(tempsum>1000000007)    tempsum=tempsum%1000000007;
        temp2=(pow(2,i));
        // cout << temp2 <<endl;
        // cout << tempsum<< endl;
        if(temp2>1000000007)    temp2=temp2%1000000007;
        tempsum*=temp2;
        sum+=tempsum;
        if(sum>1000000007)    sum=sum%1000000007;

    }
    cout << sum << endl;
    return 0;

}
