
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;
typedef long long ll;

int main(){

 int n = 5,k;
 int a[n];

 for(int i=0;i<5;i++)
    cin>>a[i];

    cin>>k;

 for(int i=0;i<n-1;i++)
 {
    for(int j=i+1;j<n;j++)
    {
        if(a[j] - a[i] > k){
        cout<<":("<<endl;
         return 0; }
    }
 }

 cout<<"Yay!"<<endl;


return 0;
}