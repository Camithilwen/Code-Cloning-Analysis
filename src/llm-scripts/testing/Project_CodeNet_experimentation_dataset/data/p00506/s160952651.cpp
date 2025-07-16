#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    int c;
    while((c=a%b)!=0){
        a=b;
        b=c;
    }
    return b;
}
vector<int> divisor(int n){
    vector<int> div;
    for(int i=1;i<=n;i++){
        if(n%i==0){
            div.push_back(n/i);
        }
    }
    sort(div.begin(),div.end());
    return div;
}
int main(void){
    int n,A[3],gcdA;
    vector<int> div;
    cin>>n;
    if(n==2){
        cin>>A[0]>>A[1];
        gcdA=gcd(A[0],A[1]);
        vector<int> div=divisor(gcdA);
        for(int i=0;i<div.size();i++){
            cout<<div[i]<<endl;
        }
    }else{
        cin>>A[0]>>A[1]>>A[2];
        gcdA=gcd(A[0],gcd(A[1],A[2]));
        vector<int> div=divisor(gcdA);
        for(int i=0;i<div.size();i++){
            cout<<div[i]<<endl;
        }
    }
    return 0;
}
