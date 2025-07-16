#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define ll long long 
int ctoi(char c) {return c-'0';}/*char to int*/
int gcd(ll a,ll b){return b?gcd(b,a%b):a;}/*MAX*/
int lcm(ll a,ll b){return a*b/gcd(a,b);}/*MIN*/
bool primecheck(ll n){/*sosuu*/if(n < 2) return false;else{for(int i = 2; i * i <= n; i++){if(n % i == 0) return false;}return true;}}
int  main(){
double n,sum=0;
  cin >>n;
  vector<double>a(n),b(n);
  for(int i =0;i<n;i++){
    double z;
    cin >>z;
    sum+=z;
    a.at(i)=z;
    b.at(i)=z;
    }
  sum/=n;
  for(int i=0;i<n;i++){
    a.at(i)=abs(a.at(i)-sum);
    b.at(i)=a.at(i);
    }
  sort(a.begin(),a.end());
  for(int i=0;i<n;i++){
     if(a.at(0)==b.at(i)){
       cout << i <<endl;
       break;
       }
    }
}





