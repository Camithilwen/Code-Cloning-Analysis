#include <cstdio>
#include <iostream>
#include <iomanip>
#include <string> 
#include <vector> 
using namespace std;
  
int main(){
    /*??£???????????????????????????
            int a[2];
            cin >> a[1] >> a[2];
            cout << "[+] " << a[1] + a[2] << endl;
            cout << "[-] " << a[1] - a[2] << endl;
            cout << "[*] " << a[1] * a[2] << endl;
            cout << "[/] " << a[1] / a[2] << endl;
    */

    int a;
    while(cin >> a){
        if(a == 0){break;}
        int ans[10] = {0,0,0,0,0,0,0,0,0,0};
        string ans2[10] = {"","","","","","","","","",""};
        int p;
        for(int i = 1;a >= i;i++){
            cin >> p;ans[p]++;
        }
        for(int i = 0;9 >= i;i++){
            if(ans[i] == 0){
                ans2[i] = "-";
            }else{
                for(int ii = 1;ans[i] >= ii;ii++){
                    ans2[i] += "*";
                }
            }
            cout << ans2[i] << endl;
        }

    }
}