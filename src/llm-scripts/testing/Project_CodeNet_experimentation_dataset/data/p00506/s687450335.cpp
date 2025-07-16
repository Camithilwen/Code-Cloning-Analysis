#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,mini = 100000000;
    cin >> n;
    int num[n];
    for(int i=0;i<n;i++){
        cin >> num[i];
        mini = min(num[i],mini);
    }
    for(int i=1;i<=mini;i++){
        if(n == 2){
            if(num[0]%i == 0 && num[1]%i == 0) cout << i << endl;
        }
        else if(n == 3){
            if(num[0]%i == 0 && num[1]%i == 0 && num[2]%i == 0) cout << i << endl;
        }
    }
}