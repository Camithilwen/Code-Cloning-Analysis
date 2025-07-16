#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int x[n],y[n];
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    int p[10]={0,1,2,3,4,5,6,7,8,9};

    double sum=0;
    int divide=0;

    do{
        for(int i=0;i<n-1;i++) sum+=sqrt(pow(x[p[i+1]]-x[p[i]],2)+pow(y[p[i+1]]-y[p[i]],2));
        divide++;
    }while(next_permutation(p,p+n));

    cout<<fixed<<setprecision(7)<<sum/divide<<endl;
}
