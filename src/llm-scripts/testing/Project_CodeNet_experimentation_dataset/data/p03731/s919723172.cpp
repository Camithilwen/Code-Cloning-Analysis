#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,T;
    cin>>N>>T;
    vector<int>t(N);
    for(int i=0;i<N;i++){
        cin>>t[i];
    }
    int a=N*T;
    for(int i=1;i<N;i++){
        if((T-(t[i]-t[i-1]))>0){
            a-=(T-(t[i]-t[i-1]));
        }
    }
    cout<<a<<endl;
    return 0;
}