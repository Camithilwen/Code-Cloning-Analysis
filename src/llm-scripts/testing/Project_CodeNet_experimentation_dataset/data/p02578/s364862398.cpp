#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long a[n];
    for(int i=0;i<n;i++)cin >> a[i];
    long dai = 0;
    for(int i=1;i<n;i++){
        if(a[i] >= a[i-1]){
            continue;
        }else{
            dai += a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }
    cout << dai << endl;
}