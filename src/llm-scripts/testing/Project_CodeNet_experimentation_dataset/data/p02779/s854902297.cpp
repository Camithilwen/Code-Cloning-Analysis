#include  <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
int x[n],i=0;
int z=0;
for (;i<n;i++){
cin>>x[i];
if(z==0&&i>0){
int j=i-1;
if(x[j]==x[i]||x[j-1]==x[i])
z++;
}
}
if(z==0){
sort(x,x+n);
int j=n-1;
int m=n/2+1;
int k=n/2-1;
for (int i=0;i<n/4+2;i++){
if(x[i+1]==x[i]||x[j]==x[j-1]||x[m]==x[m-1]||x[k]==x[k+1]){
z++;
break;
}
else{
j--;
m++;
k--;
}
}
}
if(z==0)
cout<<"YES";
else
cout<<"NO";
return 0;
}
