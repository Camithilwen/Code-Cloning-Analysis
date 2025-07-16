#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void){
    int a, b, h = 100, w = 100;
    string s[100];
    char wht = '.', blk = '#';
    cin >> a >> b;
    if(a > b){
        int t = a;
        a = b;
        b = t;
        wht = '#';
        blk = '.';
    }
    for(int i=0;i<h;i++){
        s[i] = string(w, wht);
    }
    for(int i=1;i<h&&b>0;i+=4){
        for(int j=1;j<w&&b>0;j+=4){
            for(int k=-1;k<=1;k++){
                for(int l=-1;l<=1;l++){
                    s[i+k][j+l] = blk;
                }
            }
            b--;
        }
    }
    a--;
    for(int i=1;i<h&&a>0;i+=4){
        for(int j=1;j<w&&a>0;j+=4){
            s[i][j] = wht;
            a--;
        }
    }
    
    cout << h << " " << w << endl;
    for(int i=0;i<h;i++){
        cout << s[i] << endl;
    }
}
