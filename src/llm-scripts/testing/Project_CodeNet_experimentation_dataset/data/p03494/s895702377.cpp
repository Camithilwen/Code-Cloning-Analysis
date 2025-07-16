#include<iostream>
using namespace std;

int main(){
    int n;
    int a;
    int count = 1e9;
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> a;
        int key = 0;
        while(a%2 == 0){
            a /= 2;
            key++;
        }
        if(key<count){
            count = key;
        }
    }
    cout << count << endl;
    return 0;
}