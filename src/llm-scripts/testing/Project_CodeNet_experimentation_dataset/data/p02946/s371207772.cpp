#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(void){
    // Your code here!
    long long int N,H,W,i,j,k,ans,count,cost,tmp;
    long long int S[200010];
    long long int Ssum[200010];
    string T;
    bool flag;
    count=0;
    ans=std::pow(10,18);
    flag=false;
    cin >>N>>H;
    for (i=H-(N-1);i<=H+(N-1);i++){
        if (i==H+(N-1)){
            
            cout <<i <<endl;
        }
        else{
            cout <<i << " ";
        }
    
    }

    
    

    return 0;
    
}
