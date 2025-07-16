#include <iostream>
#include <algorithm>
using namespace std;

int m, n, p[1001], pp[1001*1001];

int main(){
    while( true ){
        cin >> n >> m;
        if( m == 0 && n == 0 ) break;
        for(int i = 0; i < n; i++){
            cin >> p[i];
        }
        p[n] = 0;
        n++;
        for(int i = 0; i < n*n; i++){
            pp[i] = p[i/n] + p[i%n];
        }
        sort(pp, pp + n*n);
        int cand = 0;
        int j = n*n-1;
        for(int i = 0; i <= j; i++){
            while( j >= 0 && pp[i] + pp[j] > m ) j--;
            if(j >= 0){
                cand = max(cand, pp[i] + pp[j]);
            }
        }
        cout << cand << endl;
    }
    return 0;
}