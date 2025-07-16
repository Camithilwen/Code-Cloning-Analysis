#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,N) for(int i=0; i<N; i++) ;
int main() {
int N;
cin>>N;
ll answer=0;
for(int i=01; i<N+1; i++){
    if(i%3==0||i%5==0){
    }
    else{
    answer+=i;
    }
}
cout<<answer<<endl;
}