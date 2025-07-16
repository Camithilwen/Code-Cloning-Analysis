#include<bits/stdc++.h>
using namespace std;

int main(){
  long long int n;
  cin>>n;
  cout<<(1+n)*n/2-(3+n-n%3)*(n-n%3)/3/2-(5+n-n%5)*(n-n%5)/5/2+(15+n-n%15)*(n-n%15)/15/2<<endl;
}
  