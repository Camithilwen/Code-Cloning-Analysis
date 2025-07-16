#include<iostream>

using namespace std;

int main(){
    int H, W, A, B;
    cin >> H >> W >> A >> B;
    for(int i=1; i<=H; i++){
        for(int j=1; j<=W; j++){
            if((i<=B && j<=A) || (i>B && j>A)){
                cout << 0;
            } else{
                cout << 1;
            }
        }
        cout << endl;
    }
    
}