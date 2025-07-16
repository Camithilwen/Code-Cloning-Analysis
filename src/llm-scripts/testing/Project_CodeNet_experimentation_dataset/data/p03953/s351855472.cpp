#include <iostream>
#define SIZE 100000
using namespace std;

void copy(int *res, int *ori, int n){
    for(int i=0;i<n;i++){
        *(res+i) = *(ori+i);
    }
}

void mult(int *res, int *a, int n){
    for(int i=0;i<n;i++){
        *(res+i) = *(a + *(res+i));
    }
}

void pow(int *res, int *a, long long b, int n){
    int base[SIZE], tmp[SIZE];
    for(int i=0;i<n;i++){
        *(base+i) = *(a+i);
        *(res+i) = i;
    }
    while(b > 0){
        if(b%2 == 0){
            copy(tmp, base, n);
            mult(tmp, base, n);
            copy(base, tmp, n);
            b /= 2;
        }else{
            mult(res, base, n);
            b--;
        }
    }
}

int main(void){
    int n, m, p[SIZE], q[SIZE];
    long long k;
    long long x[SIZE], y[SIZE];
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x[i];
        p[i] = i;
        if(i>0){
            y[i-1] = x[i] - x[i-1];
        }
    }
    cin >> m >> k;
    for(int i=0;i<m;i++){
        int a, t;
        cin >> a;
        a--;
        t = p[a];
        p[a] = p[a-1];
        p[a-1] = t;
    }
    pow(q, p, k, n-1);

    for(int i=0;i<n;i++){
        if(i > 0){
            x[i] = x[i-1] + y[q[i-1]];
        }
        cout << x[i] << endl;
    }/*
    for(int i=0;i<n;i++){
        cout << i << " : " << q[i] << endl;
        cout << i << "y : " << y[i] << endl;
    }*/
}
