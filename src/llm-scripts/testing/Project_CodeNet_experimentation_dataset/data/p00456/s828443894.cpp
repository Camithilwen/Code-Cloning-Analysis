#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    
    vector<int> W(10),K(10);
    
    for(int i=0;i<10;i++) scanf("%d",&W[i]);
    for(int i=0;i<10;i++) scanf("%d",&K[i]);
    
    sort(W.begin(),W.end());
    sort(K.begin(),K.end());
    
    printf("%d %d\n",W[7]+W[8]+W[9],K[7]+K[8]+K[9]);
    
    return 0;
}