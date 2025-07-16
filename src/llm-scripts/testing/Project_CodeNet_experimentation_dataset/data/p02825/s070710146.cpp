#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int64_t n; 

// 4*4
char moji4[4][4] = {
    { 'a' , 'b', 'c', 'c' },
    { 'a' , 'b', 'd', 'd' },
    { 'e' , 'e', 'f', 'g' },
    { 'h' , 'h', 'f', 'g' },
};
// 5*5
char moji5[5][5] = {
    { '.', '.', 'a', 'b', 'c' },
    { '.', '.', 'a', 'b', 'c' },
    { 'd', 'd', 'e', 'f', 'f' },
    { 'g', 'g', 'e', '.', 'h' },
    { 'i', 'i', 'j', 'j', 'h' },
};
// 6*6
char moji6[6][6] = {
    { '.', '.', '.', 'a', 'b', 'c' },
    { '.', '.', '.', 'a', 'b', 'c' },
    { 'd', '.', 'e', 'e', '.', 'f' },
    { 'd', 'g', 'g', '.', '.', 'f' },
    { 'h', 'h', 'i', '.', 'j', 'j' },
    { 'k', 'k', 'i', 'l', 'l', '.' },
};
// 7*7
char moji7[7][7] = {
    { 'a', 'a', 'b', 'b', 'c', 'c', '.', },
    { 'd', 'd', 'e', 'e', 'f', '.', '.', },
    { '.', '.', 'g', 'g', 'f', 'h', 'h', },
    { '.', '.', '.', '.', 'i', 'j', 'k', },
    { '.', '.', '.', '.', 'i', 'j', 'k', },
    { 'l', 'm', '.', '.', '.', '.', 'n', },
    { 'l', 'm', '.', '.', '.', '.', 'n', },
};
int main() {

    // 入力
    cin >> n;

    if(n==2){
        cout << -1;
        return 0;
    }else if(n==3){
        cout << 'a' << 'a' << '.' << "\n";
        cout << '.' << '.' << 'a' << "\n";
        cout << '.' << '.' << 'a' << "\n";
        return 0;

    }

    char waku[n][n];
    
    int data = n/4;
    int mod = n%4;

    for(int i=0; i<n; i++){
        
        int num = i/4;

        if(num<data-1||mod==0){
            for(int j=0; j<n; j++){
                if(j>=num*4&&j<=num*4+3){
                    waku[i][j]=moji4[i%4][j%4];
                }else{
                    waku[i][j]='.';
                }
            }   
        }else{
            if(mod+4==5){
                for(int j=0; j<n; j++){
                    if(j>=(data-1)*4&&j<=(data-1)*4+4){
                        waku[i][j]=moji5[i-(data-1)*4][j-(data-1)*4];
                    }else{
                        waku[i][j]='.';
                    }
                }   
            }else if(mod+4==6){
                for(int j=0; j<n; j++){
                    if(j>=(data-1)*4&&j<=(data-1)*4+5){
                        waku[i][j]=moji6[i-(data-1)*4][j-(data-1)*4];
                    }else{
                        waku[i][j]='.';
                    }
                }   
            }else if(mod+4==7){
                for(int j=0; j<n; j++){
                    if(j>=(data-1)*4&&j<=(data-1)*4+6){
                        waku[i][j]=moji7[i-(data-1)*4][j-(data-1)*4];
                    }else{
                        waku[i][j]='.';
                    }
                }   
            }
        } 
    }


    for(int i=0; i<n; i++){
        
        for(int j=0; j<n; j++){
            cout << waku[i][j];
        }  
        cout << "\n";
    }
    return 0;
}
