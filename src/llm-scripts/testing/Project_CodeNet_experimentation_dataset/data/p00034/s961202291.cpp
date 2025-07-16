#include <iostream>
using namespace std;

int main(){
    int l[10];
    int v[2];
    while(scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &l[0], &l[1],
                &l[2], &l[3], &l[4], &l[5], &l[6], &l[7], &l[8], &l[9], &v[0], &v[1]) != EOF){
        double sum = 0.0;
        int i;
        for(i=0; i<10; ++i) sum += l[i];
        double l1 = sum * v[0] / (v[0] + v[1]);
        sum = 0.0;
        for(i=0; i<10; ++i){
            sum += l[i];
            if(l1 <= sum) break;
        }
        cout << i+1 << endl;
    }
    return 0;
}