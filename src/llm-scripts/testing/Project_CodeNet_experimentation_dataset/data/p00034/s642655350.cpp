#include<iostream>
using namespace std;

int main(){
    int L;
    int l[10];
    int v1, v2;
    int st, la;
    double pass;
    double time;
    char comma;
    while(cin >> l[0]){
        for(int i=1;i<10;i++){
            cin >> comma >> L;
            l[i] = L + l[i-1];
        }
        cin >> comma >> v1 >> comma >> v2;
        time = l[9] / (double)(v1+v2);
        pass = time * v1;
        for(int i=0;i<10;i++){
            if(pass <= l[i]){
                cout << i+1 << endl;
                break;
            }
        }
    }
}