#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#define rep(i,N) for(int i=0; i<N; i++)
using namespace std;

int main(){
    int D, T, S;
    cin >> D >> T >> S;
    if(D<=T*S){
        cout<<"Yes"<<endl;
    }else{
        cout << "No"<<endl;
    }
    
}