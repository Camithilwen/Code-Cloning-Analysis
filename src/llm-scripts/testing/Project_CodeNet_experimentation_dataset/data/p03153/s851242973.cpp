#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
    ll N,D;
    ll A[200005];
    cin>>N>>D;
    ll ret = D*(N-1);
    for(int i = 0;i < N;i++){
        cin>>A[i];
        ret += A[i];
    }
    for(int i = 1;i < N;i++){
        A[i]=min(A[i-1]+D,A[i]);
    }
    for(int i = N-2;i >=0;i--){
        A[i]=min(A[i+1]+D,A[i]);
    }
    for(int i = 1;i < N-1;i++){
        ret += A[i];
    }
    cout<<ret<<endl;
    
}
