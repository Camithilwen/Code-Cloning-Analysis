#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <functional>
using namespace std;
using T=tuple<int64_t,int>;

int main(){
    int64_t N,X;
    cin>>N>>X;
    vector<int64_t> B(N),L(N),U(N);
    for(int i=0;i<N;i++){
        cin>>B[i]>>L[i]>>U[i];
    }
    vector<T> V;
    for(int i=0;i<N;i++){
        V.emplace_back(U[i]*(X-B[i])+L[i]*B[i],i);
    }
    sort(V.begin(), V.end(),greater<T>());
    function<bool(int64_t)> test = [&](int64_t sum){
        int64_t total=0;
        for(int i=0;i<N;i++){
            int idx;
            tie(ignore,idx)=V[i];
            if(i<(sum+X-1)/X){
                total+=U[idx]*(X-B[idx]);
            }else{
                total+=-L[idx]*B[idx];
            }
        }
        if(sum%X==0){
            return total>=0;
        }
        int64_t maximum=-10000000000000;
        for(int i=0;i<N;i++){
            int idx;
            tie(ignore,idx)=V[i];
            int64_t diff = max(U[idx]*(sum%X-B[idx]),L[idx]*(sum%X-B[idx]));
            if(i<(sum+X-1)/X){
                maximum = max(maximum, total-U[idx]*(X-B[idx])+diff);
            }else{
                int edge = get<1>(V[(sum+X-1)/X-1]);
                maximum = max(maximum, total-U[edge]*(X-B[edge])-L[edge]*B[edge]+L[idx]*B[idx]+diff);
            }
        }
        // cout<<sum<<' '<<maximum<<' '<<total<<endl;
        return maximum>=0;
    };
    int64_t lb=0,ub=X*N;
    while(ub-lb>1){
        int64_t mid=(lb+ub)/2;
        if(test(mid)){
            ub=mid;
        }else{
            lb=mid;
        }
    }
    if(lb==0&&test(lb)){
        cout<<lb<<endl;
    }else{
        cout<<ub<<endl;
    }
    return 0;
}