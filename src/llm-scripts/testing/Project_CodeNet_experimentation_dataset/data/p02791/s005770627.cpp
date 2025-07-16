#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6;
int arr[maxn],n;
int main() {
  cin>>n;
  bool flag;
  int ans=1;
  int temp;
  cin>>arr[0];
  temp=arr[0];
  for(int i=1;i<n;i++)
  {
  	 cin>>arr[i];
	 if(arr[i]<temp)
  	 ans+=1;
  	 temp=min(arr[i],temp);
  }
 	cout<<ans;
      
}