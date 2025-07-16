#include <bits/stdc++.h>
using namespace std;

void Sum(int data[3],int K){
    
    data[2] *= 2;
    
    if(K == 1){
        int sum = 0;
        for(int i=0;i<3;i++) sum += data[i];
        cout << sum << endl;
    }
    else{
        Sum(data,K-1);
    }
}

int main(void){
    
    int data[3];
    int K;
    
    for(int i=0;i<3;i++) cin >> data[i];
    cin >> K;
    sort(data,data+3);
    
    Sum(data,K); 
    
}