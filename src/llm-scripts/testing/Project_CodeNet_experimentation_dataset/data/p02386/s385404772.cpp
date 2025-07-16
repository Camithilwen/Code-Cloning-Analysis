#include <iostream>
using namespace std;


int D[100][6];
//回転を定義
void spin(int n,char c)
{
    if(c=='E'){
        swap(D[n][0],D[n][3]);swap(D[n][3],D[n][5]);swap(D[n][5],D[n][2]);
    }
    else if(c=='W'){
        swap(D[n][0],D[n][2]);swap(D[n][2],D[n][5]);swap(D[n][5],D[n][3]);
    }
    else if(c=='S'){
        swap(D[n][0],D[n][1]);swap(D[n][0],D[n][4]);swap(D[n][4],D[n][5]);
    }
    else if(c=='N'){
        swap(D[n][0],D[n][1]);swap(D[n][1],D[n][5]);swap(D[n][5],D[n][4]);
    }
}

int main() {
    //ダイスを一括で入力
    int ans = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> D[i][j];
        }
    }
    for (int i = 0; i < n ; i++) {
        for (int j = i + 1; j <= n; j++) {
            //i個目のダイスとj個目のダイスを比較
            //回転して前面を合わせる
            char SWS[10]={"SSSSWSSSS"};
            for(int k=0; k<10; k++){
                if(D[i][1] == D[j][1]) break;
                spin(j, SWS[k]);
            }
            //回転して上面を合わせる
            for(int k=0; k<4; k++){
                if(D[i][0] == D[j][0]){
                    if(D[i][1] == D[j][1] && D[i][2] == D[j][2] && D[i][3] == D[j][3] && D[i][4] == D[j][4] && D[i][5] == D[j][5])
                        ans++;
                }
                spin(j, 'W');
            }
        }
    }
    //出力

    if (ans == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}