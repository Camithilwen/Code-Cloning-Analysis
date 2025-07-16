#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main(){
int n,i,j,k,p,count=0;
set<int>::iterator it;
vector<int>x,y;
cin>>n;
for(i=0;i<n;i++){
    cin>>p;
    x.push_back(p);
}
sort(x.begin(),x.end());

for(i=0;i<n;i++){
        if(x[i]==x[i+1]){
    x[i]=0;
    x[i+1]=0;
}
}
for(i=0;i<n;i++){
    if(x[i]!=0){
        count++;
    }
}
cout<<count;
}