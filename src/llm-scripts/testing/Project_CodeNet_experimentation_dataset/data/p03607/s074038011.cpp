#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long N;cin>>N;
    std::vector<long long>A(N);
    for(long long i=0;i<N;i++){
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    long long ans=0;
    long long tmp=0;
    for(long long i=1;i<N;i++){
        if(A[i]==A[i-1]){
            tmp++;
            if(i==N-1){
                if(tmp%2==0){
                    ans++;
                }    
            }
        }
        else{
            if(tmp%2==0){
                ans++;
            }
            tmp=0;
        }
    }
    if(A[N-1]!=A[N-2]){
        ans++;            
    }
    cout<<ans<<endl;
    return 0;
}
