#include <iostream>
#include <cstdio>
using namespace std;
 
#define N 2
void InsertionSort(int* a, int n, int g);
void ShellSort(int* a, int n);
 
int a[1000005];
int cnt = 0;
 
int main(void){
    int n;
    cin >> n;
 
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
 
    ShellSort(a, n);
 
 
    cout << cnt << endl;
 
    for(int i=0; i<n; i++){
        printf("%d\n", a[i]);
    }
 
    return 0;
}
 
void InsertionSort(int* a, int n, int g){
    for(int i=g; i<n; i++){
        int v = a[i];
        int j = i - g;
        while(j >= 0 && a[j] > v){
            a[j+g] = a[j];
            j = j - g;
            cnt++;
        }
        a[j+g] = v;
    }
}
 
void ShellSort(int* a, int n){
    int g[100001];
    g[0] = 1;
    int i=0;
    while(g[i] <= n && i<100){
        g[i+1] = g[i] * 3 + 1;
        i++;
    }
    int m = i;
    for(int i=m-1; i>=0; i--){
        InsertionSort(a, n, g[i]);
    }
 
    cout << m << endl;
    for(int i=m-1; i>0; i--){
        printf("%d ", g[i]);
    }
    printf("%d\n", g[0]);
}