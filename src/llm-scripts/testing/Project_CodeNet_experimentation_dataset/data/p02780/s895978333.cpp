#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iomanip>
using ll=long long;
using namespace std;

int main(){
    int N,K;
    cin>>N>>K;
    vector<int> P(N+2);
    for(int i=0;i<N;i++){
        cin>>P[i];
    }

    int tmp=0;
    for(int i=0;i<K;i++){
        tmp+=P[i];
    }
    int maxnum=tmp;
    for(int i=0;i+K<N;i++){
        tmp-=P[i];
        tmp+=P[i+K];
        if(tmp>maxnum){
            maxnum=tmp;
        }
    }
    double ans=(maxnum+K)/(double)2;
    cout<<fixed<<setprecision(7)<<ans<<endl;

    return 0;
}