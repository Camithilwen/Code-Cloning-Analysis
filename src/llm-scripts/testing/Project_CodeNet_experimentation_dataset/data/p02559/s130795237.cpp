#include <iostream>
#include <string>
#include <vector>
#include <atcoder/all>
using ll=long long;
using namespace std;
using namespace atcoder;

int main(){
    int N,Q;
    cin>>N>>Q;
    fenwick_tree<ll> fw(N);
    ll a;
    for(int i=0;i<N;i++){
        cin>>a;
        fw.add(i,a);
    }

    int q,x,y;
    for(int i=0;i<Q;i++){
        cin>>q>>x>>y;
        if(q){
            cout<<fw.sum(x,y)<<endl;
        }else{
            fw.add(x,y);
        }
    }

    return 0;
}