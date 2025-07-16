#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int n,m,a[100];
    cin >> n >> m;
    while ((n!=0)||(m!=0)){
        for (int i=0;i<100;i++)
            a[i]=0;
        for (int i=1;i<=n;i++){
            int b,c;
            cin >> b;
            for (int j=1;j<=b;j++){
                cin >> c;
                a[c]++;
            }
        }
        int max=0;
        for (int i=1;i<100;i++){
            if ((a[i]>a[max])&&(a[i]>=m))
                max=i;
        }
        cout << max << endl;
        cin >> n >> m;
    }
}
