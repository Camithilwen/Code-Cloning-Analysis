#include<iostream>
using namespace std;

int main(){
    int n,x,i=3;
    cin >> n;
    while(n>=i){
        x=i;
        if(i%3==0){
            cout << ' ' << i;
        } else if(i%10==3){
            cout << ' ' << i;
        } else {
            while(x!=0){
                x/=10;
                if(x%10==3){
                cout << ' ' << i;
                break;
                }
            }            
        }
        i++;
    }
    cout << endl;
}
