#include <iostream>
using namespace std;
int prime_number(int n){
    int i;
    if(n<=1) return 0;
    for(i=2;i<=n/2;i++) if(n%i==0) return 0;
    return 1;
}

int main(){
    int i,j,k,n[10000],a=0;
    for(j=0;j<10000;j++){
        cin >> n[j];
        if(n[j]==0) break;
    }
    for(k=0;k<j;k++){
        for(i=n[k];i>4;i--) if(prime_number(i)) if(prime_number(i-2)){
            a=i;
            break;
        }
        if(a!=0) cout << i-2 << " " << i << endl;
    }
    return 0;
}
