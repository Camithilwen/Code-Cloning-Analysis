#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
    int a,b,c,n,m,i,o,p,q,r,test[1000][3],num,chk[300];
    cin >> a >> b >> c;
    m = a+b+c;
    while(m!=0){
        for(i=0; i<m; i++){
            chk[i] = 2;
        }
        cin >> n;
        num = 0;
        for(i=0; i<n; i++){
            cin >> o >> p >> q >> r;
            o--;
            p--;
            q--;
            if(r==1){
                chk[o] = 1;
                chk[p] = 1;
                chk[q] = 1;
            }else{
                test[num][0] = o;
                test[num][1] = p;
                test[num][2] = q;
                num++;
            }
        }
        for(i=0; i<num; i++){
            o = test[i][0];
            p = test[i][1];
            q = test[i][2];
            if(chk[o]==2 && chk[p]==1 && chk[q]==1){
                chk[o] = 0;
            }else if(chk[o]==1 && chk[p]==2 && chk[q]==1){
                chk[p] = 0;
            }else if(chk[o]==1 && chk[p]==1 && chk[q]==2){
                chk[q] = 0;
            }
        }
        for(i=0; i<m; i++){
            cout << chk[i] << endl;
        }
        cin >> a >> b >> c;
        m = a+b+c;
    }
    return 0;
}