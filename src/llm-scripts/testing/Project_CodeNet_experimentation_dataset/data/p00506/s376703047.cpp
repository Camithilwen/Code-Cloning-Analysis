#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
  int n;
  int a[3];

  cin >> n;
  for(int i=0;i<n;i++)cin >> a[i];
  sort(a,a+n);

  vector<int> can;
  for(int i=1;i*i<=a[0];i++){
    if(!(a[0]%i)){
      can.push_back(i);
      if(i*i!=a[0])can.push_back(a[0]/i);
    }
  }

  vector<int> ans;
  for(int i=1;i<n;i++){
    ans.clear();
    for(int j=0;j<can.size();j++){
      if(!(a[i]%can[j]))ans.push_back(can[j]);
    }
    can = ans;
  }

  sort(can.begin(),can.end());
  for(int i=0;i<can.size();i++)cout << can[i] << endl;
}