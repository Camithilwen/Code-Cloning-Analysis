#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;

int main(void){
   int N,M; 
   cin >>N>>M;
   bool AC[N];
   int WA[N];
  
   int WAsum=0;
   int ACsum=0;
   
   rep(i,N){
       WA[i]=0;
       AC[i]=false;
   }
   while(M>0){
       int p;
       string s;
       cin >> p>>s;
       M--;
       if(AC[p-1]==true){
           continue;
       }
       if(s=="AC"){
           WAsum+=WA[p-1];
           ACsum++;
           AC[p-1]=true;
           
       }
       else if(s=="WA"){
           WA[p-1]++;
       }
   }
   cout << ACsum << " "<< WAsum << endl;
  
}
