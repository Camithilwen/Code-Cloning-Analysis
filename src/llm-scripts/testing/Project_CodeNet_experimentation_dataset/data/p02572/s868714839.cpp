#include <iostream>
using namespace std;
#define MOD 1000000007

int main(int argc, const char * argv[]) {
    int N;
    cin>>N;
    int *A=new int[N];
    long long s=0,s2=0;
    for(int i=0;i<N;++i){
        cin>>A[i];
        s+=A[i];
        s%=MOD;
        s2+=(long long)A[i]*A[i];
        s2%=MOD;
    }
    s*=s;
    s%=MOD;
    s-=s2;
    s%=MOD;
    if(s<0){
        s+=MOD;
    }
    if(s%2==0){
        cout<<(s/2)<<endl;
    }else{
        cout<<((s+MOD)/2)<<endl;
    }
    
    delete[] A;
    return 0;
}
