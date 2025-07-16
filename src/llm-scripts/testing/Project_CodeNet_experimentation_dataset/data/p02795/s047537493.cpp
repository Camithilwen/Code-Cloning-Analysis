#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;n>i;++i)
using namespace std;
using ll=int64_t;
using vi=vector<int>;
using VI=vector<ll>;
using vis=vector<string>;
using vvi=vector<vi>;
int main(){
    int h,w,n;
    cin>>h>>w>>n;
    if(n%max(h,w)==0){
        cout<<n/max(h,w)<<endl;
        return 0;
    }
    else{
        cout<<n/max(h,w)+1<<endl;
        return 0;
    }
}