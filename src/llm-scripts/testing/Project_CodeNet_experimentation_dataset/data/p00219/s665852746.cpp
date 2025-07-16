#include<iostream>
using namespace std;
int main(){
    int n[20];
    int c[20][10];
    int l =0;
    int k;
    while(cin >> n[l]){
        if(n[l] == 0){break;}
        for (int i = 0; i< 10; i++){
            c[l][i] = 0;
        }
        for(int i= 0;i < n[l] ;i++){
            cin >> k;
            c[l][k] ++;
        }
        l ++;
    }
    for(int i = 0;i < l;i++){
        for(int j = 0;j<10;j++){
        if (c[i][j] == 0){
            cout << "-" << endl;
        }
        else{
            for(int w = 0;w < c[i][j];w++){
                cout << "*";
            }
            cout << endl;
        }
        }
    }
    return 0;
}
