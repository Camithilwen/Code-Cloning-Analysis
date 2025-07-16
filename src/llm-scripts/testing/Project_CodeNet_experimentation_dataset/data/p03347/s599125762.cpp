#include<iostream>
using namespace std;

int main() {
    int N;
    cin>>N;
    long A[N];
    for(int i=0;i<N;++i){
        cin>>A[i];
    }
    bool check = true;
    if(A[0]!=0)check = false;
    for(int i=1;i<N;++i){
        if(A[i]-A[i-1]>1)check = false;
    }
    long ans = A[N-1];
    if(check){
        for(int i=N-1;i>=1;--i){
            if(A[i]-A[i-1]!=1)ans += A[i-1];
        }
    }
    else ans = -1;
    cout<<ans<<endl;
}
