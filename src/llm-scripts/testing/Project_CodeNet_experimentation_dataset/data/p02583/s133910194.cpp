#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
    cin>>n;
    int ar[n];
    int count=0;
   for(int i=0;i<n;i++){
   cin>>ar[i];
  }
for(int i=0;i<n-2;i++){
   for(int j=i+1;j<n-1;j++){
     for(int k=j+1;k<n;k++){
       if(ar[i]+ar[j]>ar[k] && ar[i]+ar[k]>ar[j] && ar[j]+ar[k]>ar[i] && ar[i]!=ar[j] && ar[j]!=ar[k] && ar[i]!=ar[k]){
     count++;
         }
     }
  }
}
   cout<<count;
	return 0;
}