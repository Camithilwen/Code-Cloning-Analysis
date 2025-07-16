#include <bits/stdc++.h>
using namespace std;
int main(){
int N;
int counter = 0;
cin >>  N;
for(int i = 0;i < N/3 + 1;i++){
if((N - 3*(i + 1) >= 0)){
counter ++;}
else  cout << counter << endl;}
}