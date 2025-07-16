#include <iostream>
using namespace std;

int main(){
    while(1){
        int a, b, c, n, list[1001][4], parts[301], judge, defect;

        cin >> a >> b >> c >> n;
        if(a == 0 && b == 0 && c == 0){
            break;
        }

        for(int i = 1; i <= a + b + c; i++){
            parts[i] = 2;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 4; j++){
                cin >> list[i][j];
            }
            if(list[i][3] == 1){
                for(int k = 0; k < 3; k++){
                    parts[list[i][k]] = 1;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(!list[i][3]){
                judge = 0;
                for(int j = 0; j < 3; j++){
                    if(parts[list[i][j]] == 1){
                        judge++;
                    } else{
                        defect = j;
                    }
                }
                if(judge == 2){
                    parts[list[i][defect]] = 0;
                }
            }
        }

        for(int i = 1; i <= a + b + c; i++){
            cout << parts[i] << endl;
        }
    }

    return 0;
}