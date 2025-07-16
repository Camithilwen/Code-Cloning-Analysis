#include<iostream>
using namespace std;

int main(){
    int N,x;
    cin >> N >> x;
    int a[N];
    for(int i=0; i<N; i++){
        cin >> a[i];
    }

    long long total = 0;
    for(int pairIndex=0; pairIndex<N-1; pairIndex++){
        int first = pairIndex;
        int second = pairIndex+1;
        if(a[first] > x){
            int diff = a[first] - x;
            a[first] -= diff;
            total += diff;
        }
        if(a[first] + a[second] > x){
            int diff = a[first] + a[second] - x;
            a[second] -= diff;
            total += diff;
        }
    }

    cout << total << '\n';
}