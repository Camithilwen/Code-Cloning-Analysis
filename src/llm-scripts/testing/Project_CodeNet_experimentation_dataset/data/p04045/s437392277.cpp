#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int num[10];
bool is_OK(int X){
    while(X > 0){
        int n = X % 10;
        if(num[n]){
            return false;
        }
        X /= 10;
    }
    return true;
}
int main(void){
    int N,K;
    cin >> N >> K;
    int D[K];
    for(int i=0;i<K;i++){
        cin >> D[i];
    }
    
    for(int i=0;i<K;i++){
        num[D[i]]++;
    }
    int ans;
    for(int i=N;;i++){
        if(is_OK(i)){
            cout << i << endl;
            return 0;
        }
    }
}
