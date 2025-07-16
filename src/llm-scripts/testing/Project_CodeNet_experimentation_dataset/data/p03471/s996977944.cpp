#include <bits/stdc++.h>
using namespace std;
int main() {
    int N,Y;
    cin >> N >> Y;

bool fin=false;

    for(int i=0;i<(Y/10000)+1;i++){
        for(int j=0;j<((Y-10000*i)/5000)+1;j++){
            if(((Y-10000*i-5000*j)/1000)+i+j==N){
                cout << i << " " << j << " " << (Y-10000*i-5000*j)/1000 <<endl;
                fin = true; 
                break;
            }
        }
        if(fin==true)break;
    }

    if(fin==false){
        cout <<"-1 -1 -1" << endl;
    }
}